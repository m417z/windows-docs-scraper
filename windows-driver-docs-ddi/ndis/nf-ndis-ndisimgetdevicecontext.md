# NdisIMGetDeviceContext (Windows CE 5.0)

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

This function allows an NDIS intermediate driver's [MiniportInitialize](https://learn.microsoft.com/previous-versions/windows/embedded/aa447847(v=msdn.10)) function to access the device context area allocated by its [ProtocolBindAdapter](https://learn.microsoft.com/previous-versions/windows/embedded/ms919689(v=msdn.10)) function.

## Parameters

### `MiniportAdapterHandle` [in]

Specifies the handle input to **MiniportInitialize**.

## Return value

The following table shows the return values for this function.

| Value | Description |
| --- | --- |
| NDISIMGETDEVICECONTEXT | Returns access to the device context area for the virtual NIC identified by *MiniportAdapterHandle*. |
| NULL | If the driver's ProtocolBindAdapter function did not allocate such a device context area. |

## Remarks

An NDIS intermediate driver's **MiniportInitialize** function calls **NdisIMGetDeviceContext** to access the device context area for the virtual NIC it is initializing. Usually, the memory for such an area is provided by the intermediate driver's **ProtocolBindAdapter** function, which calls [NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) with a pointer to this area, thereby causing the driver's **MiniportInitialize** function to be called. However, an intermediate driver is not required to have such a context area.

On return from **NdisIMGetDeviceContext**, **MiniportInitialize** sets up the driver-defined state for the virtual NIC with whatever information the intermediate driver writer intends to be useful to still higher-level protocols that bind themselves subsequently to its virtual NIC.

Still higher level NDIS protocols bound to the same virtual NIC subsequently can access this device context area by calling [NdisIMGetBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimgetbindingcontext) from their **ProtocolBindAdapter** functions.

**OS Versions:** Windows CE .NET 4.0 and later.

## See also

- [MiniportInitialize](https://learn.microsoft.com/previous-versions/windows/embedded/aa447847(v=msdn.10))
- [NdisIMGetBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimgetbindingcontext)
- [NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex)
- [ProtocolBindAdapter](https://learn.microsoft.com/previous-versions/windows/embedded/ms919689(v=msdn.10))