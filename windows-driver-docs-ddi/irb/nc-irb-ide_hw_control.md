# IDE_HW_CONTROL callback function

## Description

The *IdeHwControl* miniport driver routine notifies the miniport driver about Plug and Play (PnP) and power events.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `ControlAction` [in]

Contains an enumerator value of type [IDE_CONTROL_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ide_control_action) that indicates the control action to perform.

### `Parameters` [in, out]

A pointer to a buffer that contains the parameters that are associated with the control action. This parameter can have one of the values in the following table.

| Control action | Parameters | Description |
| --- | --- | --- |
| **IdeStart** | Parameter points to a structure of type IDE_CHANNEL_CONFIGURATION. | Indicates that the port driver is starting the channel. |
| **IdeVendorDefined** | Parameter points to a structure of type IDE_VENDOR_DEFINED_POWER_INFO. | Indicates that there is a vendor defined power event coming. |

## Return value

*IdeHwControl* returns **TRUE** if the operation was successful. Otherwise, it returns **FALSE**.

## Remarks

The port driver makes sure that there is no outstanding I/O on the channel before it invokes this routine. The miniport driver can have its own power policy methods when the system enters a different power state. In order to achieve this, the miniport driver needs to do the following:

* Add a power policy setting scheme into the miniport driver's INF file. A GUID is needed to present a miniport driver-defined power policy. For more information about the power settings directive, see [INF AddPowerSetting Directive](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addpowersetting-directive). More information about the GUIDs can be found at [Disk settings](https://learn.microsoft.com/windows-hardware/customize/power-settings/disk-settings).
* When the miniport driver routine *IdeHwControl* is called with control action **IdeStart**:

  Check the SupportedAdvances.AdvancedChannelConfigurationSupported field in the ChannelConfiguration structure.

  Check the AdvancedChannelConfiguration->Present.VendorDefinedPower field in the ChannelConfiguration structure.

  If the values of the two fields listed previously are both **TRUE**, this version of the ATA port driver supports vendor-defined power management.

  If vendor-defined power management is supported by the ATA port driver, the miniport driver can register for special power management handling by setting the AdvancedChannelConfiguration->VendorDefinedPower.ValidGuids and AdvancedChannelConfiguration->VendorDefinedPower.Guid[] fields (the latter should be the GUID of the power policy in the miniport driver's INF file).
* After vendor-defined power management is registered, the miniport driver will be able to receive calls to its *IdeHwControl* routine with control action **IdeVendorDefined** when the system power scheme changes.
* While the miniport driver processes the *IdeHwControl* routine with control action **IdeVendorDefined**, it should do following:

  Compare the **SettingGuid** field from the parameter field of structure IDE_VENDOR_DEFINED_POWER_INFO with the GUID that the miniport driver registered to make sure that the call is for this channel. If the GUIDs do not match, the miniport driver should complete the call and take no action.

  Get the **Value** field from the parameter field of structure IDE_VENDOR_DEFINED_POWER_INFO and perform the appropriate miniport driver-specific power management action.

## See also

[AtaPortGetUncachedExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetuncachedextension)