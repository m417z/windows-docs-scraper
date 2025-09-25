## Description

**SCSI_SUPPORTED_CONTROL_TYPE_LIST** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiQuerySupportedUnitControlTypes** or [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiQuerySupportedControlTypes**.

## Members

### `MaxControlType`

The number of entries in the **SupportedTypeList** array. A miniport's implementation needs to handle the case where the value of **MaxControlType** might be larger than the **ScsiUnitControlMax** (for unit control) or **ScsiAdapterControlMax** (for adapter control) value that the driver is compiled with.

### `SupportedTypeList`

Points to a caller-allocated array of **BOOLEAN** values that indicate the unit or adapter control types implemented by the miniport driver. The port driver initializes each element to **FALSE** for both unit devices and adapters. The miniport driver must not set any element beyond **SupportedTypeList**[**MaxControlType** - 1]. See Remarks for additional details.

## Remarks

When **SCSI_SUPPORTED_CONTROL_TYPE_LIST** is being used for *unit control*, the miniport driver sets the corresponding element in the **SupportedTypeList** array to **TRUE** for each operation it supports:

- **SupportedTypeList[ScsiQuerySupportedControlTypes]**
- **SupportedTypeList[ScsiUnitUsage]**
- **SupportedTypeList[ScsiUnitStart]**
- **SupportedTypeList[ScsiUnitPower]**
- **SupportedTypeList[ScsiUnitPoFxPowerInfo]**
- **SupportedTypeList[ScsiUnitPoFxPowerRequired]**
- **SupportedTypeList[ScsiUnitPoFxPowerActive]**
- **SupportedTypeList[ScsiUnitPoFxPowerSetFState]**
- **SupportedTypeList[ScsiUnitPoFxPowerControl]**
- **SupportedTypeList[ScsiUnitRemove]**
- **SupportedTypeList[ScsiUnitSurpriseRemoval]**
- **SupportedTypeList[ScsiUnitRichDescription]**
- **SupportedTypeList[ScsiUnitQueryBusType]** (Windows 10 version 20H1 and later)
- **SupportedTypeList[ScsiUnitQueryFruId]** (Windows 10 version 20H1 and later)

If a miniport indicates support for **ScsiUnitQueryBusType** or **ScsiUnitQueryFruId**, it must also call [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) with **StorportFeatureBusTypeUnitControl** or **StorportFeatureFruIdUnitControl** set, respectively.

When **SCSI_SUPPORTED_CONTROL_TYPE_LIST** is being used for *adapter control*, the miniport driver sets the corresponding element in the **SupportedTypeList** array to **TRUE** for each operation it supports:

- **SupportedTypeList[ScsiQuerySupportedControlTypes]**
- **SupportedTypeList[ScsiStopAdapter]**
- **SupportedTypeList[ScsiRestartAdapter]**
- **SupportedTypeList[ScsiSetBootConfig]**
- **SupportedTypeList[ScsiSetRunningConfig]**
- **SupportedTypeList[ScsiPowerSettingNotification]**
- **SupportedTypeList[ScsiAdapterPower]**
- **SupportedTypeList[ScsiAdapterPoFxPowerRequired]**
- **SupportedTypeList[ScsiAdapterPoFxPowerActive]**
- **SupportedTypeList[ScsiAdapterPoFxPowerSetFState]**
- **SupportedTypeList[ScsiAdapterPoFxPowerControl]**
- **SupportedTypeList[ScsiAdapterPrepareForBusReScan]**
- **SupportedTypeList[ScsiAdapterSystemPowerHints]**
- **SupportedTypeList[ScsiAdapterFilterResourceRequirements]**
- **SupportedTypeList[ScsiAdapterPoFxMaxOperationalPower]**
- **SupportedTypeList[ScsiAdapterPoFxSetPerfState]**
- **SupportedTypeList[ScsiAdapterSurpriseRemoval]**
- **SupportedTypeList[ScsiAdapterSerialNumber]**
- **SupportedTypeList[ScsiAdapterCryptoOperation]**
- **SupportedTypeList[ScsiAdapterQueryFruId]**
- **SupportedTypeList[ScsiAdapterSetEventLogging]**

If a miniport indicates support for **ScsiAdapterQueryFruId** or **ScsiAdapterSetEventLogging**, it must also call [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) with **StorportFeatureFruIdAdapterControl** or **StorportFeatureSetEventLoggingAdapterControl** set, respectively.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist)