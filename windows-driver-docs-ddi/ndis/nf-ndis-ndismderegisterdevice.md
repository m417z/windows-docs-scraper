# NdisMDeregisterDevice function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

The **NdisMDeregisterDevice** function removes from the system a device object that was created with [**NdisMRegisterDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdevice). **NdisMDeregisterDevice** also removes the symbolic link that is associated with this device object.

## Parameters

### `NdisDeviceHandle` [in]

Specifies the handle returned by **NdisMRegisterDevice** that identifies the device object to be deregistered.

## Return value

**NdisMDeregisterDevice** returns NDIS\_STATUS\_SUCCESS if the device object and its associated symbolic link object are deleted.

## Remarks

A driver calls **NdisMDeregisterDevice** from its **Halt** or **Unload** function to deregister a stand-alone device object that it previously created with [**NdisMRegisterDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdevice). The driver must call **NdisMDeregisterDevice** when it is being unloaded or when its **DriverEntry** routine encounters a fatal initialization error, such as an inability to obtain system resources.

When **NdisMRegisterDevice** is called, there cannot be any outstanding user-mode open operations on the device object being deleted. If there are, a system error occurs.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**MiniportHalt**](https://learn.microsoft.com/previous-versions/windows/embedded/aa447845(v=msdn.10))
- [**NdisMRegisterDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdevice)
- [**NdisMRegisterUnloadHandler**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterunloadhandler)