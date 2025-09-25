# NdisDeregisterDeviceEx function

## Description

The
**NdisDeregisterDeviceEx** function removes, from the system, a device object that was created by the
[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex) function.

## Parameters

### `NdisDeviceHandle` [in]

The handle returned by
[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex) that identifies
the device object to be deregistered.

## Remarks

The
**NdisDeregisterDeviceEx** function removes a device object that was created by the
[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex) function.
**NdisDeregisterDeviceEx** also removes the symbolic link that is associated with this device
object.

## See also

[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex)