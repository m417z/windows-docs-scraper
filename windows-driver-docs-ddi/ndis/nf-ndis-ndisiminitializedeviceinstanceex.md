# NdisIMInitializeDeviceInstanceEx function

## Description

The
**NdisIMInitializeDeviceInstanceEx** function initiates the initialization operation for a virtual
miniport and optionally sets up state information about the virtual miniport for subsequently bound
protocol drivers.

## Parameters

### `DriverHandle` [in]

The miniport driver handle that the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function returns at
*NdisMiniportDriverHandle* .

### `DriverInstance` [in]

A pointer to an NDIS_STRING type that describes a caller-initialized counted string in the
system-default character set. The string contains the name of the registry key in which the driver
stores information about a virtual miniport and, possibly, binding-specific information. For Microsoft
Windows 2000 and later drivers, this string contains Unicode characters. That is, for Windows 2000 and
later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `DeviceContext` [in, optional]

A pointer to caller-supplied memory to be set up with driver-defined device context information
about the virtual miniport, which still higher level protocol drivers that subsequently bind themselves
to this virtual miniport can use. This parameter can be **NULL** if the intermediate driver has no such
device context area.

## Return value

**NdisIMInitializeDeviceInstanceEx** can return either of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS initiated the initialization operation for the intermediate driver's virtual miniport. |
| **NDIS_STATUS_NOT_ACCEPTED** | **NdisIMInitializeDeviceInstanceEx** failed because the device specified by *DriverHandle* has already been initialized. |

## Remarks

An NDIS intermediate driver should call
**NdisIMInitializeDeviceInstanceEx** from its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function. A
failure to call
**NdisIMInitializeDeviceInstanceEx** from an NDIS intermediate driver effectively prevents that driver
from loading successfully.

Before it calls
**NdisIMInitializeDeviceInstanceEx**, the intermediate driver's
*ProtocolBindAdapterEx* function should bind to any underlying miniport drivers that are required for
the intermediate driver to function. The
*ProtocolBindAdapterEx* function can allocate an area at
*DeviceContext* as well, possibly setting it up with intermediate driver-determined information about
the capabilities of the underlying miniport adapter and that was collected by
*ProtocolBindAdapterEx*. The intermediate driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
might use such information subsequently to set up this context area with information about the driver's
virtual miniport.

The intermediate driver's call to
**NdisIMInitializeDeviceInstanceEx** causes NDIS to call the intermediate driver's
*MiniportInitializeEx* function, if NDIS receives an
[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) IRP to start the device.
If NDIS does not receive such an IRP, NDIS will not call the intermediate driver's
*MiniportInitializeEx* function.

The call to
*MiniportInitializeEx* can happen at a later time and therefore is not necessarily within the context
of the call to
**NdisIMInitializeDeviceInstanceEx**. If NDIS never calls
*MiniportInitializeEx* for the virtual miniport that is referenced in a call to
**NdisIMInitializeDeviceInstanceEx** and the intermediate driver no longer requires the virtual
miniport, the intermediate driver should call the
[NdisIMCancelInitializeDeviceInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimcancelinitializedeviceinstance) function to cancel the initialization of the virtual miniport.
For example, suppose that an intermediate driver creates a virtual miniport in response to a successful
binding to an underlying miniport adapter. If that binding is removed before NDIS calls
*MiniportInitializeEx*, the intermediate driver should call
**NdisIMCancelInitializeDeviceInstance** to cancel the initialization of the virtual miniport.

*MiniportInitializeEx* allocates any resources that the driver requires to carry out network I/O
operations, such as calling the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function, and to initialize the driver's virtual miniport to an
operational state. Then, higher-level protocol drivers can bind themselves to its virtual miniport when
the intermediate driver's initialization is completed successfully.

After
*MiniportInitializeEx* returns control, the intermediate driver's device context area, if any, can
contain any intermediate-driver-defined data that subsequently enables all higher-level protocol drivers
that are bound to the same virtual miniport to access information in that context area. Such a
higher-level protocol driver can query the intermediate-driver-supplied device context with the
[NdisIMGetBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimgetbindingcontext) function.

Before NDIS calls an intermediate driver's
*MiniportInitializeEx* function, the driver can call
[NdisIMCancelInitializeDeviceInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimcancelinitializedeviceinstance) to cancel the initialization operation.

After NDIS calls an intermediate driver's
*MiniportInitializeEx* function, the driver must call
[NdisIMDeInitializeDeviceInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimdeinitializedeviceinstance) to reverse the initialization operation.

## See also

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisIMCancelInitializeDeviceInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimcancelinitializedeviceinstance)

[NdisIMDeInitializeDeviceInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimdeinitializedeviceinstance)

[NdisIMGetBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimgetbindingcontext)

[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex)

[NdisInitializeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializestring)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)