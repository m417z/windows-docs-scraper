# SET_OPTIONS callback function

## Description

NDIS calls a driver's
*XxxSetOptions* function to allow the driver to register optional services. This function is defined as *MiniportSetOptions* for miniport drivers, *ProtocolSetOptions* for protocol drivers, or *FilterSetOptions* for filter drivers.

**Note** You must declare the function by using the **Xxx_SET_OPTIONS** type. For more
information, see the Examples section.

## Parameters

### `NdisDriverHandle` [in]

A handle that identifies a driver. NDIS returns this handle to the driver when it returns from the driver registration function ([NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) for miniport drivers, [NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) for protocol drivers, and [NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) for filter drivers).

### `DriverContext` [in]

The handle that the driver passed to
**NdisRegisterXxxDriver** that identifies the driver context area, where Xxx is the type of driver (Miniport, Protocol, or Filter).

## Return value

*XxxSetOptions* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *XxxSetOptions* successfully registered the driver's optional services and resources. |
| **NDIS_STATUS_RESOURCES** | *XxxSetOptions* could not allocate the resources that the driver requires. |
| **NDIS_STATUS_XXX or NTSTATUS_XXX** | The driver's attempt to register options failed. Usually, such an error status is propagated from an **Ndis*Xxx*** function or a kernel-mode support routine. |

## Remarks

*XxxSetOptions* is an optional function. NDIS calls
*XxxSetOptions* within the context of the driver's call to the
**NdisRegisterXxxDriver** function, where Xxx is the type of driver (Miniport, Protocol, or Filter).

*XxxSetOptions* registers optional services and can allocate other driver resources. To register
optional
*MiniportXxx*, *ProtocolXxx*, or *FilterXxx* functions, the driver calls the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.
The driver passes the handle from the
*NdisDriverHandle* parameter at the
*NdisHandle* parameter of
**NdisSetOptionalHandlers** and passes a characteristics structure at the
*OptionalHandlers* parameter.

Miniport drivers can apply to the optional services defined in the following characteristics structures:

[NDIS_MINIPORT_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_co_characteristics)

[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics)

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_provider_chimney_offload_generic_characteristics)(see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload))

[NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_provider_chimney_offload_tcp_characteristics)(see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload))

Protocol drivers can apply to the optional services defined in the following characteristics structures:

[NDIS_PROTOCOL_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_co_characteristics)

[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers)

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

There are no optional filter driver services in the current Windows version.

NDIS can call the driver's other
*MiniportXxx*, *ProtocolXxx*, or *FilterXxx* functions at any time after
*XxxSetOptions* returns. The driver should be prepared to be called back at its initialization function:([MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) for miniport drivers, [ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) for protocol drivers, and [FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) for filter drivers).

For miniport drivers, the
miniport adapters are in the
*Halted* state before the NDIS calls
*MiniportInitializeEx*. For protocol drivers, the protocol bindings are in the
*Unbound* state before the NDIS calls
*ProtocolBindAdapterEx*. For filter drivers, the filter modules
are in the
*Detached* state before the NDIS calls
*FilterAttach*.

If an attempt to allocate resources or services fails,
*XxxSetOptions* should undo all the allocations that succeeded before it returns control with a
status other than NDIS_STATUS_SUCCESS.

Miniport and filter drivers' *XxxDriverUnload* should undo all the operations that were performed in *XxxSetOptions*

NDIS calls
*XxxSetOptions* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *XxxSetOptions* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

In the Ndis.h header file, the SET_OPTIONS callback function is further defined as follows:

```
typedef SET_OPTIONS (*SET_OPTIONS_HANDLER);
typedef SET_OPTIONS (MINIPORT_SET_OPTIONS);
typedef SET_OPTIONS (PROTOCOL_SET_OPTIONS);
typedef SET_OPTIONS (FILTER_SET_OPTIONS);
```

This enables all NDIS drivers to implement their XxxSetOptions callback functions with the same syntax. Miniport drivers use the **MINIPORT_SET_OPTIONS** type, protocol drivers use the **PROTOCOL_SET_OPTIONS** type, and filter drivers use the **FILTER_SET_OPTIONS** type.

For example, to define a *MiniportSetOptions* function that is named "MySetOptions", use the **MINIPORT_SET_OPTIONS** type as shown in this code example:

```
MINIPORT_SET_OPTIONS MySetOptions;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MySetOptions(
    NDIS_HANDLE  NdisDriverHandle,
    NDIS_HANDLE  DriverContext
    )
  {...}
```

The **SET_OPTIONS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **SET_OPTIONS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_CO_CALL_MANAGER_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_call_manager_optional_handlers)

[NDIS_CO_CLIENT_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_co_client_optional_handlers)

[NDIS_PROTOCOL_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_co_characteristics)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)