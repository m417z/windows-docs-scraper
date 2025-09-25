# NdisMCmRegisterAddressFamilyEx function

## Description

The
**NdisMCmRegisterAddressFamilyEx** function registers an address family (AF) for communication between a
miniport call manager (MCM) and CoNDIS clients.

## Parameters

### `MiniportAdapterHandle` [in]

An NDIS-supplied handle that identifies a miniport adapter. This handle is an input parameter to
the MCM's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `AddressFamily` [in]

A pointer to a
[CO_ADDRESS_FAMILY](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545368(v=vs.85)) structure that identifies
the AF that the MCM driver supports.

The pointer becomes an input parameter to the
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) functions of all of the CoNDIS clients that are bound to this MCM
driver.

## Return value

**NdisMCmRegisterAddressFamilyEx** can return any of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport driver registered with NDIS as a call manager for the AF that the *AddressFamily* parameter specified, so NDIS will call the [ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) functions of all of the clients that bind to the MCM driver. |
| **NDIS_STATUS_RESOURCES** | The requested operation failed because NDIS could not allocate sufficient memory or initialize the state information that it uses to track the MCM driver as a call manager of the specified AF. |
| **NDIS_STATUS_FAILURE** | NDIS failed the call to **NdisMCmRegisterAddressFamilyEx**, possibly for one of the following reasons:<br><br>* The caller was not registered as a connection-oriented miniport driver.<br>* The caller tried to register a duplicate AF for a given miniport adapter. |

## Remarks

NDIS MCMs, which register as NDIS miniport drivers by calling the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function, should call the
**NdisMCmRegisterAddressFamilyEx** function to register an AF. Stand-alone call managers should instead
call the
[NdisCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregisteraddressfamilyex) function.

To register an AF for a miniport adapter, the MCM should call
**NdisMCmRegisterAddressFamilyEx** from the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

The driver of any network interface card (NIC) that has on-board connection-oriented signaling support
can register itself as an MCM driver for better performance in managing calls. If a driver registers as
an MCM driver, any stand-alone call manager with the NIC driver's own call-management support is
displaced.

An MCM driver calls
**NdisMCmRegisterAddressFamilyEx** after it has determined that a NIC is fully operational and the
driver can complete network I/O operations. That is, such an MCM registers itself as a call manager and
advertises its specific signaling services for CoNDIS clients.

After
*MiniportInitializeEx* returns control with a successful registration as a call manager, NDIS calls
the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) functions
of potential clients and, then, the
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) functions of all of the clients that bind themselves to the associated
MCM miniport adapter. These clients then cause NDIS to call the
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function of the
MCM.

An MCM can support more than one AF for a single NIC that it manages. The MCM driver must call
**NdisMCmRegisterAddressFamilyEx** once for each AF that it registers for a miniport adapter. Only one
MCM driver can support a particular type of AF for clients that are bound to a given miniport
adapter.

## See also

[CO_ADDRESS_FAMILY](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545368(v=vs.85))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregisteraddressfamilyex)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)

[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request)

[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete)