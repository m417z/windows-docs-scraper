# NdisMCmCreateVc function

## Description

**NdisMCmCreateVc** sets up a connection endpoint on which an MCM driver can dispatch an incoming-call
offer to a client.

## Parameters

### `MiniportAdapterHandle` [in]

Specifies the NDIS-supplied handle originally input to
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `NdisAfHandle` [in]

Specifies the handle that identifies the client that is the target of an incoming call. The MCM
driver obtained this handle as an input parameter to its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

### `MiniportVcContext` [in]

Specifies the handle to a caller-supplied resident context area in which the MCM driver maintains
state for this VC. NDIS passes this handle back to the MCM driver in all subsequent calls concerning
this VC if the call to
**NdisMCmCreateVc** succeeds.

### `NdisVcHandle` [out]

Pointer to a caller-supplied variable that must be initialized to **NULL** before
**NdisMCmCreateVc** is called. On return from a successful call, this variable has been set to an
NDIS-supplied handle for the newly created VC. The caller must save this handle for subsequent calls to
connection-oriented
**Ndis*Xxx*** functions concerning this VC.

## Return value

**NdisMCmCreateVc** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS created the VC successfully. |
| **NDIS_STATUS_RESOURCES** | NDIS could not allocate sufficient memory to set up the VC. |
| **NDIS_STATUS_FAILURE** | The given *NdisAfHandle* is invalid. |
| **NDIS_STATUS_*XXX*** | The client failed the creation of the VC for some reason, and NDIS has propagated the error status returned by its [ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function to the MCM driver. |

## Remarks

An MCM driver creates a VC with
**NdisMCmCreateVc** to represent an incoming offer of a connection from a remote node directed to a SAP
that has already been registered with the MCM driver.

In the process of VC creation, NDIS supplies an
*NdisVcHandle* to the client and the MCM driver. This handle identifies the virtual connection for
the client and miniport driver to which subsequent requests concerning the given VC are directed. Each
driver must treat this VC handle as an opaque variable, passing it unmodified and uninterpreted in
subsequent calls to certain connection-oriented NDIS library functions.

Usually, callers of
**NdisMCmCreateVc** store the returned
*NdisVcHandle* in the caller-allocated state area at
*MiniportVcContext* . NDIS passes an
*NdisVcHandle* as an input parameter to the
*ProtocolCoCreateVc* function of the appropriate client whenever an MCM driver creates a VC.

When an MCM driver processes the offer of an incoming call directed to one of its registered SAPs, it
must call
**NdisMCmCreateVc** first. As a synchronous operation, NDIS calls the client's
*ProtocolCoCreateVc* function before
**NdisMCmCreateVc** returns control. If its call to
**NdisMCmCreateVc** succeeds, the MCM driver can proceed in notifying the appropriate client, passing
the returned value at
*NdisVcHandle* to
[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall).

The driver writer determines whether an MCM driver has an (internal)
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function that the
driver calls in the context of setting up connections for outgoing and incoming calls.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmCreateVc**. Stand-alone call managers and clients, which register themselves with NDIS as
protocol drivers, call
**NdisCoCreateVc** instead.

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)