# PcUnregisterIoTimeout function

## Description

The **PcUnregisterIoTimeout** function unregisters a driver-supplied I/O-timer callback routine for a specified device object.

**Note** This function is deprecated for Windows 8 and later versions of Windows. For Windows on Arm systems, this function is commented out in the PortCls class driver and is inaccessible.

## Parameters

### `pDeviceObject` [in]

Pointer to the same device object that the driver supplied when it previously called [PcRegisterIoTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteriotimeout). The device object is a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `pTimerRoutine` [in]

Pointer to the same I/O-timer callback routine that the driver supplied when it previously called [PcRegisterIoTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteriotimeout)

### `pContext` [in]

Pointer to the same driver-determined context that the driver supplied when it previously called [PcRegisterIoTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteriotimeout)

## Return value

**PcUnregisterIoTimeout** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code. The following table shows some of the possible error codes.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | Indicates that no timer callback with the same device object, callback routine, and context is currently registered. |

## Remarks

This call succeeds only if a time-out callback with the same device object, timer routine, and context was previously registered with a call to the [PcRegisterIoTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteriotimeout) function.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[PcRegisterIoTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteriotimeout)