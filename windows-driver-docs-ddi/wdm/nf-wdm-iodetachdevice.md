# IoDetachDevice function

## Description

The **IoDetachDevice** routine releases an attachment between the caller's device object and a lower driver's device object.

## Parameters

### `TargetDevice` [in, out]

Pointer to the lower driver's device object. The caller previously called [IoAttachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevice) or [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack) successfully to get this pointer.

## Remarks

**IoDetachDevice** decrements the reference count of the *TargetDevice* object. If the reference count goes to zero and the lower driver has been marked for an unload operation, the lower driver is unloaded.

## See also

[IoAttachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevice)

[IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack)