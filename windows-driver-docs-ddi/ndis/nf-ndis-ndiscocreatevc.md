# NdisCoCreateVc function

## Description

**NdisCoCreateVc** sets up a connection endpoint from which a client can make outgoing calls or on which
a stand-alone call manager can dispatch incoming calls.

## Parameters

### `NdisBindingHandle` [in]

Specifies the handle returned by
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) that identifies the
target NIC or virtual adapter of the next-lower driver to which the caller is bound.

### `NdisAfHandle` [in, optional]

Specifies the handle returned by
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) if
the caller is a client. A call manager sets this parameter to **NULL** if it is creating a VC for itself,
such as a VC to a network switch. When it creates a VC for incoming call notifications, a call manager
passes the AF handle that it saved in its per-AF state designated by the
*CallMgrAfContext* that was passed as an input parameter to its
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function.

### `ProtocolVcContext` [in]

Specifies the handle to a caller-supplied resident context area in which the caller maintains
state for this VC. NDIS passes this handle back to the VC creator in all subsequent calls concerning
this endpoint if the call to
**NdisCoCreateVc** succeeds.

### `NdisVcHandle` [in, out]

Pointer to a caller-supplied variable that must be initialized to **NULL** when
**NdisCoCreateVc** is called. On return from a successful call, this points to a variable that NDIS
has set to its handle for the newly created VC. The caller must save this handle for subsequent calls to
connection-oriented Ndis
*Xxx* functions.

## Return value

**NdisCoCreateVc** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS created the VC successfully. |
| **NDIS_STATUS_RESOURCES** | NDIS could not allocate sufficient memory to set up the VC. |
| **NDIS_STATUS_FAILURE** | The given *NdisAfHandle* is invalid. |
| **NDIS_STATUS_ *XXX*** | The underlying miniport driver failed the creation of the VC for a miniport driver-determined reason, which NDIS has propagated to the caller. |

## Remarks

A client or stand-alone call manager creates a VC with
**NdisCoCreateVc**, depending on whether the VC represents an outgoing or incoming call,
respectively.

In the process of VC creation, NDIS supplies an
*NdisVcHandle* to the client, the call manager, and the miniport driver to which both protocol
drivers are bound. This handle identifies the virtual circuit for the client, call manager, and miniport
driver to which subsequent requests concerning the given VC are directed. Each driver must treat this VC
handle as an opaque variable, passing it unmodified and uninterpreted in subsequent calls to certain
connection-oriented NDIS library functions.

Usually, callers of
**NdisCoCreateVc** store the returned
*NdisVcHandle* in the caller-allocated state area at
*ProtocolVcContext* . NDIS passes this handle as an input parameter to the
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) and
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) functions of the
other two drivers involved in each creation of a VC.

To make an outgoing call, a client must call
**NdisCoCreateVc** first. As a synchronous operation, NDIS calls the underlying miniport driver's
*MiniportCoCreateVc* function and the call manager's
*ProtocolCoCreateVc* function before
**NdisCoCreateVc** returns control. If its call to
**NdisCoCreateVc** succeeds, the client can proceed in making an outgoing call, passing the returned
*NdisVcHandle* to
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall).

When its
[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists) function processes the offer of an incoming call directed to one of
its registered SAPs, a call manager must call
**NdisCoCreateVc** first. As a synchronous operation, NDIS calls the underlying miniport driver's
*MiniportCoCreateVc* function and the client's
*ProtocolCoCreateVc* function before
**NdisCoCreateVc** returns control. If its call to
**NdisCoCreateVc** succeeds, the call manager can proceed in notifying the appropriate client, passing
the returned value at
*NdisVcHandle* to
[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall).

Stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCoCreateVc**. Connection-oriented miniport drivers that provide integrated call-management
support call
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc), instead.

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)