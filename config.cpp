class CfgPatches
{
  class Bicycle_Lights
  {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    requiredAddons[] = {
      "DZ_Data",
      "DZ_Gear_Camping",
      "DZ_Gear_Tools",
      "DZ_Gear_Consumables",
      "DZ_Vehicles_Wheeled",
      "DZ_Sounds_Effects",
      "DZ_Scripts",
      "Bicycle"
    };
  };
};

class CfgMods
{
  class Bicycle_Lights
  {
    type = "mod";
    author = "WILDLANDZ Team";
    name = "Bicycle_Lights";
    dir = "Bicycle_Lights";
    dependencies[] = {"Game", "World", "Mission"};
    class defs
    {
      class worldScriptModule
      {
        value = "";
        files[] = {"Bicycle_Lights/scripts/4_World"};
      };
    };
  };
};

class CfgSlots
{
  class Slot_BicycleFlashlight
  {
    name = "BicycleFlashlight";
    displayName = "$STR_CfgVehicles_Flashlight0";
    ghostIcon = "set:dayz_inventory image:flashlight";
  };
};

class CfgNonAIVehicles
{
  class ProxyAttachment;

  class Proxyflashlight: ProxyAttachment
  {
    scope = 2;
    inventorySlot[] = {"BicycleFlashlight"};
    model = "\DZ\gear\tools\flashlight.p3d";
  };
};

class CfgVehicles
{
  class Inventory_Base;
  class CarScript;

  class Flashlight: Inventory_Base
  {
    inventorySlot[] += {"BicycleFlashlight"};
  };

  class ItemBicycle_Base: Inventory_Base
  {
    model = "Bicycle_Lights\itembicycle.p3d";
    attachments[] = {
      "bicycle_wheel_1_1",
      "bicycle_wheel_1_2",
      "BicycleFlashlight",
      "Chemlight"
    };
    class GUIInventoryAttachmentsProps
    {
      class Chassis
      {
        name = "$STR_attachment_Chassis0";
        description = "";
        icon = "set:bicycle_gui image:bicycle_icon";
        attachmentSlots[] = {"bicycle_wheel_1_1", "bicycle_wheel_1_2"};
      };
      class Lights
      {
        name = "Lights";
        description = "";
        icon = "set:dayz_inventory image:lights";
        attachmentSlots[] = {"BicycleFlashlight", "Chemlight"};
      };
    };
  };

  class Bicycle_Base: CarScript
  {
    model = "Bicycle_Lights\bicycle.p3d";
    attachments[] = {
      "bicycle_wheel_1_1",
      "bicycle_wheel_1_2",
      "bicycle_wheel_2_1",
      "bicycle_wheel_2_2",
      "Att_CombinationLock",
      "BicycleFlashlight",
      "Chemlight"
    };
    class GUIInventoryAttachmentsProps
    {
      class Chassis
      {
        name = "$STR_attachment_Chassis0";
        description = "";
        icon = "set:bicycle_gui image:bicycle_icon";
        attachmentSlots[] = {"bicycle_wheel_1_1", "bicycle_wheel_1_2"};
      };
      class Security
      {
        name = "Security";
        description = "";
        icon = "set:bicycle_gui image:bicycle_icon";
        attachmentSlots[] = {"Att_CombinationLock"};
      };
      class Lights
      {
        name = "Lights";
        description = "";
        icon = "set:dayz_inventory image:lights";
        attachmentSlots[] = {"BicycleFlashlight", "Chemlight"};
      };
    };
  };

  class ItemLady_Bicycle: ItemBicycle_Base
  {
    model = "Bicycle_Lights\itemlady_bicycle.p3d";
    attachments[] = {
      "ladybicycle_wheel_1_1",
      "ladybicycle_wheel_1_2",
      "BicycleFlashlight",
      "Chemlight"
    };
    class GUIInventoryAttachmentsProps
    {
      class Chassis
      {
        name = "$STR_attachment_Chassis0";
        description = "";
        icon = "set:bicycle_gui image:bicycle_icon";
        attachmentSlots[] = {"ladybicycle_wheel_1_1", "ladybicycle_wheel_1_2"};
      };
      class Lights
      {
        name = "Lights";
        description = "";
        icon = "set:dayz_inventory image:lights";
        attachmentSlots[] = {"BicycleFlashlight", "Chemlight"};
      };
    };
  };

  class Lady_Bicycle: Bicycle_Base
  {
    model = "Bicycle_Lights\lady_bicycle.p3d";
    attachments[] = {
      "ladybicycle_wheel_1_1",
      "ladybicycle_wheel_1_2",
      "ladybicycle_wheel_2_1",
      "ladybicycle_wheel_2_2",
      "Att_CombinationLock",
      "BicycleFlashlight",
      "Chemlight"
    };
    class GUIInventoryAttachmentsProps
    {
      class Chassis
      {
        name = "$STR_attachment_Chassis0";
        description = "";
        icon = "set:bicycle_gui image:bicycle_icon";
        attachmentSlots[] = {"ladybicycle_wheel_1_1", "ladybicycle_wheel_1_2"};
      };
      class Security
      {
        name = "Security";
        description = "";
        icon = "set:bicycle_gui image:bicycle_icon";
        attachmentSlots[] = {"Att_CombinationLock"};
      };
      class Lights
      {
        name = "Lights";
        description = "";
        icon = "set:dayz_inventory image:lights";
        attachmentSlots[] = {"BicycleFlashlight", "Chemlight"};
      };
    };
  };
};
