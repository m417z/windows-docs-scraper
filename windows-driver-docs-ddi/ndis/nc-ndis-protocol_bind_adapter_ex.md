# PROTOCOL_BIND_ADAPTER_EX callback function

## Description

NDIS calls a protocol driver's
*ProtocolBindAdapterEx* function to request the driver to bind to a miniport
adapter.

**Note** You must declare the function by using the **PROTOCOL_BIND_ADAPTER_EX** type. For more
information, see the following Examples section.

## Parameters

### `ProtocolDriverContext` [in]

A handle to a driver-allocated context area where the driver maintains state and configuration
information. The protocol driver passed this context area to the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function.

### `BindContext` [in]

The handle that identifies the NDIS context area for this bind operation.

### `BindParameters` [in]

A pointer to an
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure that
NDIS created.

## Return value

*ProtocolBindAdapterEx* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *ProtocolBindAdapterEx* successfully completed the binding to the underlying miniport adapter. |
| **NDIS_STATUS_PENDING** | *ProtocolBindAdapterEx* did not complete the bind operation and the operation will be completed asynchronously. The protocol driver must call the [NdisCompleteBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletebindadapterex) function when the operation is complete. |
| **NDIS_STATUS_RESOURCES** | *ProtocolBindAdapterEx* could not allocate the resources that the driver requires to carry out network I/O operations. |
| **NDIS_STATUS_XXX or NTSTATUS_XXX** | The protocol driver's attempt to set up a binding failed. Usually, such an error status is propagated from an **Ndis*Xxx*** function or a kernel-mode support routine. |

## Remarks

*ProtocolBindAdapterEx* is a required function. NDIS calls
*ProtocolBindAdapterEx* to perform binding operations whenever an underlying
miniport adapter, to which the protocol driver can bind, becomes available.

*ProtocolBindAdapterEx* allocates sufficient memory to maintain the binding
context information and calls the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function to bind
itself to the underlying miniport adapter.
*ProtocolBindAdapterEx* passes a pointer to the binding context information at
the
*ProtocolBindingContext* parameter of
**NdisOpenAdapterEx**.
*ProtocolBindAdapterEx* passes the value at the
**AdapterName** member from its
*BindParameters* parameter as the
**AdapterName** member of the
*OpenParameters* parameter of
**NdisOpenAdapterEx***.*

Before the driver calls
**NdisOpenAdapterEx**, the driver can pass the pointer at
*BindParameters* to the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex) function
to read the configuration parameters that are associated with a miniport adapter.

After opening the miniport adapter successfully, the driver can pass the handle from
*NdisHandle* parameter of
**NdisOpenAdapterEx** to
**NdisOpenConfigurationEx** to obtain a handle to the registry location where the configuration
parameters for a protocol binding are stored.

*ProtocolBindAdapterEx* passes
**NdisOpenAdapterEx** a pointer to an array of medium type values that lists the types of media that
the protocol driver can support. This list is a subset of the
[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium) types. NDIS indicates the selected
medium type at the
**SelectedMediumIndex** parameter of the structure at
*OpenParameters*.

If
**NdisOpenAdapterEx** returns an error status,
*ProtocolBindAdapterEx* returns that error status, releases any per-binding
resources that the protocol driver allocated, and returns control immediately.

If
**NdisOpenAdapterEx** returns NDIS_STATUS_SUCCESS,
*ProtocolBindAdapterEx* can allocate the remaining resources that the protocol
driver needs to carry out network I/O on the binding. The driver can also configure any binding-specific
context information that the driver uses to track network I/O operations.

If
**NdisOpenAdapterEx** returns NDIS_STATUS_PENDING, NDIS calls the protocol driver's
[ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex) function after the open operation is complete.
*ProtocolOpenAdapterCompleteEx* can complete the binding operations.
*ProtocolBindAdapterEx* can store the
*BindContext* handle in the binding context area. NDIS passes
*ProtocolBindingContext* as an input parameter to the driver's
*ProtocolOpenAdapterCompleteEx* function.

If
**NdisOpenAdapterEx** returns NDIS_STATUS_PENDING, NDIS sets the
**SelectedMediumIndex** member of the structure at the
*OpenParameters* parameter and the value of the
*NdisBindingHandle* parameter after
**NdisOpenAdapterEx** returns. NDIS sets these values before calling
*ProtocolOpenAdapterCompleteEx*. Therefore, the protocol driver must store the
open parameters structure, and the protocol binding handle in the context area at
*ProtocolBindingContext*(or any location that is valid until NDIS calls
*ProtocolOpenAdapterCompleteEx*).

A protocol driver cannot make OID requests on a binding until the open operation is complete. Because
the binding is in the paused state after the open operation is complete, the protocol driver cannot make
send requests until after NDIS restarts the binding.

After the open operation is complete,
*ProtocolBindAdapterEx* can return NDIS_STATUS_SUCCESS to complete the binding
operation.
*ProtocolBindAdapterEx* can return NDIS_STATUS_PENDING to defer the completion of
the binding operations to a later time. If
*ProtocolBindAdapterEx* returns NDIS_STATUS_PENDING, the driver must call the
[NdisCompleteBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletebindadapterex) function after the binding operation is complete.

Protocol drivers should use the
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure to
determine the underlying miniport adapter's capabilities. After the open operation is complete, depending
on the underlying media, the protocol driver can call the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function to query the
underlying miniport driver (or NDIS) about additional miniport adapter capabilities. For more information
about OID requests, see
[Protocol Driver OID Requests](https://learn.microsoft.com/windows-hardware/drivers/network/protocol-driver-oid-requests).

NDIS can call a protocol driver's
[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists) function after the driver sets up a packet filter for the binding
with the
[OID_GEN_CURRENT_PACKET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-packet-filter) OID. If the underlying miniport adapter does not use a packet filter
for incoming packets, receive indications are enabled after the open operation is complete. Protocol
drivers can receive status indications at the
[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex) function after the
open operation is complete.

Every protocol driver should allocate sufficient
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) and
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure pools. The driver
allocates network data descriptors from these pools for subsequent send operations.

If
*ProtocolBindAdapterEx* cannot allocate the resources it needs to carry out
subsequent network I/O operations, it should free all resources it has already allocated, and return an
appropriate error value.

NDIS calls a protocol driver's
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function to request the driver to unbind from an underlying miniport
adapter.

If the protocol driver successfully opens the miniport adapter but the bind operation fails (for
example, as a result of a failed OID request), the driver must close the miniport adapter from within the
context of
*ProtocolBindAdapterEx* or
*ProtocolUnbindAdapterEx*. For example, the driver calls
[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex) from
*ProtocolBindAdapterEx* and waits for the close operation to complete before the
driver returns from
*ProtocolBindAdapterEx*. As an alternative, if the driver returned
NDIS_STATUS_PENDING from
*ProtocolBindAdapterEx*, the driver can call the
[NdisUnbindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunbindadapter) function and call
**NdisCloseAdapterEx** in the
*ProtocolUnbindAdapterEx* function.

NDIS calls
*ProtocolBindAdapterEx* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *ProtocolBindAdapterEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolBindAdapterEx* function that is named "MyBindAdapterEx", use the **PROTOCOL_BIND_ADAPTER_EX** type as shown in this code example:

```
PROTOCOL_BIND_ADAPTER_EX MyBindAdapterEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyBindAdapterEx(
    NDIS_HANDLE  ProtocolDriverContext,
    NDIS_HANDLE  BindContext,
    PNDIS_BIND_PARAMETERS  BindParameters
    )
  {...}
```

The **PROTOCOL_BIND_ADAPTER_EX** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_BIND_ADAPTER_EX** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex)

[NdisCompleteBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletebindadapterex)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisUnbindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunbindadapter)

[OID_GEN_CURRENT_PACKET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-packet-filter)

[ProtocolOpenAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_open_adapter_complete_ex)

[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists)

[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)