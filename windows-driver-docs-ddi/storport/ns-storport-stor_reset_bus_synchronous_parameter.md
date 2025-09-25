## Description

**STOR_RESET_BUS_SYNCHRONOUS_PARAMETER** is the **Parameters** parameter to the miniport's [**HW_ADAPTER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine when [**ControlType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_adapter_control_type) is **ScsiAdapterResetBusSynchronous**.

## Members

### `Version`

Size, in bytes, of this structure. The structure size serves as the version number.

### `Size`

Size, in bytes, of this structure plus all of its variable-sized fields.

### `PathId`

Identifies the SCSI bus to be reset.

### `Reserved`

Reserved for future use.

## Remarks

Storport calls the miniport's [**HW_ADAPTER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine with a control type of [**ScsiAdapterResetBusSynchronous**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_adapter_control_type) only if the miniport has declared support for [**StorportFeatureResetBusSynchronous**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_feature_type) feature.

**ScsiAdapterResetBusSynchronous** control is invoked at PASSIVE_LEVEL, so the miniport is able to do the synchronous bus reset safely.

## See also

[**HW_ADAPTER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**SCSI_ADAPTER_CONTROL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_adapter_control_type)

[**STORPORT_FEATURE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_feature_type)