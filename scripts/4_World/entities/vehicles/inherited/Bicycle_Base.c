modded class Bicycle_Base
{
	static const string FLASHLIGHT_SLOT = "BicycleFlashlight";

	Flashlight GetMountedFlashlight()
	{
		return Flashlight.Cast(FindAttachmentBySlotName(FLASHLIGHT_SLOT));
	}

	bool CanSwitchMountedFlashlight(bool on)
	{
		Flashlight mountedLight = GetMountedFlashlight();
		if (!mountedLight || mountedLight.IsRuined() || !mountedLight.GetCompEM())
			return false;

		if (on)
			return mountedLight.GetCompEM().CanSwitchOn() && mountedLight.GetCompEM().CanWork();

		return mountedLight.GetCompEM().CanSwitchOff();
	}

	void SwitchMountedFlashlight(bool on)
	{
		if (!GetGame().IsServer() && GetGame().IsMultiplayer())
			return;

		if (!CanSwitchMountedFlashlight(on))
			return;

		if (on)
			GetMountedFlashlight().GetCompEM().SwitchOn();
		else
			GetMountedFlashlight().GetCompEM().SwitchOff();
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionToggleBicycleFlashlight);
		AddAction(ActionTurnOnBicycleFlashlight);
		AddAction(ActionTurnOffBicycleFlashlight);
	}
};
