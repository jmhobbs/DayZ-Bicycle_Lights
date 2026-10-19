// Rider toggles the mounted flashlight with the headlights key (modelled on vanilla ActionSwitchLights)
class ActionToggleBicycleFlashlight : ActionInteractBase
{
	void ActionToggleBicycleFlashlight()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_HEADLIGHT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "#switch_lights";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override typename GetInputType()
	{
		return ToggleVehicleLightsActionInput;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool CanBeUsedInVehicle()
	{
		return true;
	}

	protected Bicycle_Base GetRiddenBicycle(PlayerBase player)
	{
		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
		if (!vehCommand)
			return null;

		Bicycle_Base bicycle = Bicycle_Base.Cast(vehCommand.GetTransport());
		if (!bicycle)
			return null;

		if (bicycle.GetSeatAnimationType(bicycle.CrewMemberIndex(player)) != DayZPlayerConstants.VEHICLESEAT_DRIVER)
			return null;

		return bicycle;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Bicycle_Base bicycle = GetRiddenBicycle(player);
		if (!bicycle)
			return false;

		Flashlight mountedLight = bicycle.GetMountedFlashlight();
		if (!mountedLight || !mountedLight.GetCompEM())
			return false;

		return bicycle.CanSwitchMountedFlashlight(!mountedLight.GetCompEM().IsSwitchedOn());
	}

	override void OnExecuteServer(ActionData action_data)
	{
		Bicycle_Base bicycle = GetRiddenBicycle(action_data.m_Player);
		if (!bicycle)
			return;

		Flashlight mountedLight = bicycle.GetMountedFlashlight();
		if (mountedLight && mountedLight.GetCompEM())
			bicycle.SwitchMountedFlashlight(!mountedLight.GetCompEM().IsSwitchedOn());
	}
}

// On-foot switch on/off while looking at the bike (modelled on upstream ActionTurnOnBicycleDynamo)
class ActionTurnOnBicycleFlashlight : ActionInteractBase
{
	void ActionTurnOnBicycleFlashlight()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#switch_on";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursorNoRuinCheck();
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Bicycle_Base bicycle = Bicycle_Base.Cast(target.GetObject());
		return bicycle && bicycle.CanSwitchMountedFlashlight(true);
	}

	override void OnExecuteServer(ActionData action_data)
	{
		Bicycle_Base bicycle = Bicycle_Base.Cast(action_data.m_Target.GetObject());
		if (bicycle)
			bicycle.SwitchMountedFlashlight(true);
	}
}

class ActionTurnOffBicycleFlashlight : ActionInteractBase
{
	void ActionTurnOffBicycleFlashlight()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#switch_off";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursorNoRuinCheck();
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Bicycle_Base bicycle = Bicycle_Base.Cast(target.GetObject());
		return bicycle && bicycle.CanSwitchMountedFlashlight(false);
	}

	override void OnExecuteServer(ActionData action_data)
	{
		Bicycle_Base bicycle = Bicycle_Base.Cast(action_data.m_Target.GetObject());
		if (bicycle)
			bicycle.SwitchMountedFlashlight(false);
	}
}
