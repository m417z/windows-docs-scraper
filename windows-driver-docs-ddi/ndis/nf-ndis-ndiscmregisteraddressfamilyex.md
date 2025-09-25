# NdisCmRegisterAddressFamilyEx function

## Description

The
**NdisCmRegisterAddressFamilyEx** function registers an address family (AF) for communication between
CoNDIS drivers.

## Parameters

### `NdisBindingHandle` [in]

A handle that NDIS provided at the
*NdisBindingHandle* parameter of the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function. This handle
identifies the binding to associate with the AF.

### `AddressFamily` [in]

A pointer to a
[CO_ADDRESS_FAMILY](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545368(v=vs.85)) structure that identifies
the call manager and the AF that it supports for the binding that
*NdisBindingHandle* specifies.

The pointer for
*AddressFamily* becomes an input parameter to the
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) functions of all of the clients that are bound to the same CoNDIS
miniport adapter.

## Return value

**NdisCmRegisterAddressFamilyEx** can return any of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The protocol driver registered the AF that the *AddressFamily* points to, so NDIS will call the [ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) functions of all of the clients that bind themselves to the same miniport adapter. |
| **NDIS_STATUS_RESOURCES** | The requested operation failed because NDIS could not allocate sufficient memory or initialize the state that it uses to track the call manager or the specified AF. |
| **NDIS_STATUS_FAILURE** | NDIS failed the call to **NdisCmRegisterAddressFamilyEx**, possibly for one of the following reasons:<br><br>* The caller was not registered as a connection-oriented protocol driver.<br>* The miniport driver that the caller is bound to was not registered as a connection-oriented   miniport driver.<br>* Another call manager has already registered the specified AF.<br>* The caller's binding is being closed. |

## Remarks

NDIS stand-alone call managers, which register as NDIS protocol drivers by calling the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function, should call the
**NdisCmRegisterAddressFamilyEx** function to register an AF. Miniport call managers (MCMs) must
instead call the
[NdisMCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmregisteraddressfamilyex) function.

To register an AF for a binding, the stand-alone call manager should call
**NdisCmRegisterAddressFamilyEx** from the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

A stand-alone call manager's
*ProtocolBindAdapterEx* function first establishes the binding to the underlying miniport driver by
calling the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function. Each time
NDIS calls
*ProtocolBindAdapterEx* with another handle at the
*BindContext* parameter,
*ProtocolBindAdapterEx* establishes a binding and registers an AF that it supports. In other words, a
stand-alone call manager eventually registers an AF for each binding on which it provides call-management
services to connection-oriented clients.

The call manager can support more than one AF and can support more than one AF for a single binding.
However, only one call manager can support a given AF for clients that are bound to a given miniport
adapter.

When a call manager's
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function
returns control after a successful binding operation, NDIS calls the
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) functions of all of the clients that are bound to the same miniport
adapter.

## See also

[CO_ADDRESS_FAMILY](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545368(v=vs.85))

[NdisMCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmregisteraddressfamilyex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)