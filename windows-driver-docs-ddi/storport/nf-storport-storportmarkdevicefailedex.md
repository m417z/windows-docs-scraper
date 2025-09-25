# StorPortMarkDeviceFailedEx function

## Description

The **StorPortMarkDeviceFailedEx** routine marks a device with failed status and provides data that might be needed for diagnosis.

## Parameters

### `HwDeviceExtension`

Pointer to the hardware device extension for the host bus adapter (HBA).

### `StorAddress`

Storage unit device address. This parameter is NULL for adapter devices.

### `Flags`

Indicates the behavior being requested by the miniport. *Flags* can be set to one of the following values.

| Flag | Meaning |
| ---- | ------- |
| STORPORT_MARK_DEVICE_FAILED_FLAG_REMOVE_DEVICE | Remove the failed device. |
| STORPORT_MARK_DEVICE_FAILED_FLAG_PREDICTED_FAILURE | Indicates that this is a predicted device failure. |

### `FaultCode`

Miniport-specific fault code.

### `FaultDescription`

Human-readable string that describes the fault.

### `AdditionalDataSize`

Size in bytes of the buffer that *AdditionalData* points to.

### `AdditionalData`

Pointer to a buffer containing additional data associated with the fault condition.

### `CriticalDataSize`

Size in bytes of the buffer that *CriticalData* points to.

### `CriticalData`

Pointer to a buffer containing critical data associated with the fault condition.

## Return value

**StorPortMarkDeviceFailedEx** returns a valid STOR_STATUS code.

## Remarks

A miniport driver can call this function to mark a failed device or to indicate that the device has potentially failed.

If no flags are set in *Flags*, Storport will only log the event.

The PnP manager will send an IRP to query the failed device's PnP state. If *Flags* is set to STORPORT_MARK_DEVICE_FAILED_FLAG_REMOVE_DEVICE and not set to STORPORT_MARK_DEVICE_FAILED_FLAG_PREDICTED_FAILURE, the PnP manager will then try to remove the failed device.

## See also

[**IoInvalidateDeviceState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinvalidatedevicestate)

[**StorPortMarkDeviceFailed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportmarkdevicefailed)