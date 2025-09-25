# NdisIMGetBindingContext function

## Description

The
**NdisIMGetBindingContext** function allows an NDIS protocol driver to access the device context area,
which was created by an underlying intermediate driver, for a virtual miniport to which the higher level
protocol driver is bound.

## Parameters

### `NdisBindingHandle` [in]

The binding handle that the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function returned at
the
*NdisBindingHandle* parameter that identifies the virtual miniport of the next lower intermediate
driver to which the caller is bound.

## Return value

**NdisIMGetBindingContext** returns a handle to the device context area for the given virtual
miniport, or it returns **NULL** if no such context area exists.

## Remarks

A protocol driver or intermediate driver can call
**NdisIMGetBindingContext** from its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function to
access the device context for a virtual miniport to which it is bound. The device context provides a
common context area for all overlying protocol drivers that are bound to the same underlying intermediate
driver.

Such a device context area was allocated and defined by the lower level NDIS intermediate driver and
passed to NDIS in a call to the
[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) function.

All protocol drivers that call
**NdisIMGetBindingContext** can safely assume that the underlying intermediate driver allocated its
context area from nonpaged pool. They should treat the returned context area as read-only, preserving the
state set up by the underlying NDIS intermediate driver that defined it.

## See also

[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)