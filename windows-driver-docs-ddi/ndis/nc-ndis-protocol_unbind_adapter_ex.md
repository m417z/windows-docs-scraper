# PROTOCOL_UNBIND_ADAPTER_EX callback function

## Description

NDIS calls a protocol driver's
*ProtocolUnbindAdapterEx* function to request the driver to unbind from an underlying miniport
adapter.

**Note** You must declare the function by using the **PROTOCOL_UNBIND_ADAPTER_EX** type. For more
information, see the following Examples section.

## Parameters

### `UnbindContext` [in]

The handle that identifies the NDIS context area for this unbind operation.

### `ProtocolBindingContext` [in]

A handle to a context area allocated by the protocol driver. The protocol driver maintains the
per-binding context information in this context area. The driver supplied this handle to NDIS when the
driver called the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

## Return value

*ProtocolUnbindAdapterEx* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *ProtocolUnbindAdapterEx* successfully unbound from an underlying miniport adapter. |
| **NDIS_STATUS_PENDING** | *ProtocolUnbindAdapterEx* did not complete the unbind operation and the operation will be completed asynchronously. The protocol driver must call the [NdisCompleteUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompleteunbindadapterex) function after the unbind operation is complete. |

## Remarks

*ProtocolUnbindAdapterEx* is a required function. As the reciprocal of the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function,
NDIS calls
*ProtocolUnbindAdapterEx* to release the resources that the driver allocated for network I/O
operations that are specific to a binding. A protocol driver cannot fail an unbind operation.

Before calling
*ProtocolUnbindAdapterEx*, NDIS pauses the protocol binding. To pause the binding, NDIS calls the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function and
specifics a
**NetEventPause** event.

*ProtocolUnbindAdapterEx* must call the
[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex) function to close
the binding to the underlying miniport adapter. If
**NdisCloseAdapterEx** returns NDIS_STATUS_SUCCESS, the close operation is complete. If
**NdisCloseAdapterEx** returns NDIS_STATUS_PENDING, NDIS calls the protocol driver's
[ProtocolCloseAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_close_adapter_complete_ex) function after the close operation is complete.

Before calling
**NdisCloseAdapterEx**, the protocol driver should clear the multicast address list and packet filters
for the binding. The protocol driver sets the binding multicast address list to **NULL**, and the packet
filter to zero. For more information, see
[OID_802_3_MULTICAST_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-multicast-list) and
[OID_GEN_CURRENT_PACKET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-packet-filter).

If a wake-up pattern has been specified, the protocol driver should remove it with the [OID_PNP_REMOVE_WAKE_UP_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-remove-wake-up-pattern) OID and clear the receive side scaling parameters with the [OID_GEN_RECEIVE_SCALE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters) OID. An NDIS 6.20 and later protocol driver should remove a wake-on-LAN pattern with the [OID_PM_REMOVE_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-remove-wol-pattern) OID and remove a low-power protocol offload with the [OID_PM_REMOVE_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-remove-protocol-offload) OID.

*ProtocolUnbindAdapterEx* must not free the memory at
*ProtocolBindingContext* until the close operation is complete. NDIS passes the handle at
*ProtocolBindingContext* to
*ProtocolCloseAdapterCompleteEx*.

If the protocol driver has completed the unbind operation,
*ProtocolUnbindAdapterEx* can return NDIS_STATUS_SUCCESS. If
**NdisCloseAdapterEx** returns NDIS_STATUS_PENDING,
*ProtocolUnbindAdapterEx* must wait for NDIS to call
*ProtocolCloseAdapterCompleteEx* before it can return NDIS_STATUS_SUCCESS.

*ProtocolUnbindAdapterEx* can return NDIS_STATUS_PENDING to defer the completion of the unbind
operation to a later time. If
*ProtocolUnbindAdapterEx* returns NDIS_STATUS_PENDING, the driver must eventually call the
[NdisCompleteUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompleteunbindadapterex) function to complete the unbind operation. If the
[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex) function returned
NDIS_STATUS_PENDING, the driver can complete the unbind operation in
*ProtocolCloseAdapterCompleteEx*.
*ProtocolUnbindAdapterEx* can store the handle at
*UnbindContext* in the context area at
*ProtocolBindingContext* before it calls
**NdisCloseAdapterEx**. If
*ProtocolUnbindAdapterEx* stored the handle,
*ProtocolCloseAdapterCompleteEx* can pass the handle to
**NdisCompleteUnbindAdapterEx** to complete the unbind operation.

As soon as
*ProtocolUnbindAdapterEx* calls
**NdisCloseAdapterEx**, the handle obtained from the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function at the
*NdisBindingHandle* parameter becomes invalid.
*ProtocolUnbindAdapterEx* cannot make any subsequent calls to
**Ndis*Xxx*** functions with this handle. The driver can get receive and status indications from the
underlying miniport adapter until the close operation is complete.

NDIS calls
*ProtocolUnbindAdapterEx* at IRQL = PASSIVE_LEVEL.

### Updating Power Management and RSS Settings

NDIS 6.0 and 6.1 protocol drivers should perform the following operations where applicable:

1. Remove power management wake on LAN (WOL) patterns from the miniport adapter with the
   [OID_PNP_REMOVE_WAKE_UP_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-remove-wake-up-pattern) OID.
2. Clear the receive side scaling parameters with the
   [OID_GEN_RECEIVE_SCALE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters) OID.

NDIS 6.20 and later protocol drivers should perform the following operations:

1. Remove power management WOL patterns from the miniport adapter with the
   [OID_PM_REMOVE_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-remove-wol-pattern) OID.
2. Remove power management protocol offloads from the miniport adapter with the
   [OID_PM_REMOVE_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-remove-protocol-offload) OID.

### Examples

To define a *ProtocolUnbindAdapterEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolUnbindAdapterEx* function that is named "MyUnbindAdapterEx", use the **PROTOCOL_UNBIND_ADAPTER_EX** type as shown in this code example:

```
PROTOCOL_UNBIND_ADAPTER_EX MyUnbindAdapterEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyUnbindAdapterEx(
    NDIS_HANDLE  UnbindContext,
    NDIS_HANDLE  ProtocolBindingContext
    )
  {...}
```

The **PROTOCOL_UNBIND_ADAPTER_EX** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_UNBIND_ADAPTER_EX** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex)

[NdisCompleteUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompleteunbindadapterex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[OID_802_3_MULTICAST_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-multicast-list)

[OID_GEN_CURRENT_PACKET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-packet-filter)

[OID_GEN_RECEIVE_SCALE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters)

[OID_PNP_REMOVE_WAKE_UP_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-remove-wake-up-pattern)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolCloseAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_close_adapter_complete_ex)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)