# NdisClRegisterSap function

## Description

**NdisClRegisterSap** registers a SAP on which the client can receive incoming calls from a remote
node.

## Parameters

### `NdisAfHandle` [in]

Specifies the handle returned by
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex),
which implicitly identifies the call manager with which to register the SAP.

### `ProtocolSapContext` [in]

Specifies the handle to a caller-supplied resident context area in which the client maintains
state for this SAP after it has been opened. NDIS passes this handle back to the client in all
subsequent calls concerning this SAP if the call to
**NdisClRegisterSap** succeeds.

### `Sap` [in]

Pointer to a client-supplied specification for the SAP to be opened, formatted as a structure of
type
[CO_SAP](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545392(v=vs.85)).

### `NdisSapHandle` [out]

Pointer to a variable in which a handle to the newly registered SAP is returned if this call
succeeds.

## Return value

When
**NdisClRegisterSap** returns anything other than NDIS_STATUS_PENDING, the client should make an
internal call to its
[ProtocolClRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_register_sap_complete) function. Otherwise, NDIS calls the client's
*ProtocolClRegisterSapComplete* function when this operation is completed.

## Remarks

With a call to
**NdisClRegisterSap**, a client requests notifications of incoming calls on a particular SAP. NDIS
forwards the given SAP information to the call manager's
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function
for validation. If the given SAP is already in use or if the call manager does not recognize the
client-supplied specification at
*Sap*, the call manager fails this request.

SAP format is medium-dependent and specific to the address family supported by the call manager, which
uses registered SAPs subsequently to route incoming calls to the appropriate client. A call manager can
register SAPs for established PVCs without contacting other network components, depending on the
underlying medium.

If its call to
**NdisClRegisterSap** succeeds, the client must save the handle returned at
*NdisSapHandle* because it is a required parameter to
[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap). Callers of
**NdisClRegisterSap** usually pass a pointer to a variable in the client-allocated state area at
*ProtocolSapContext* so that NDIS can set it to the
*NdisSapHandle* if this call succeeds. NDIS passes the given
*ProtocolSapContext* to the client's registered ProtocolCl/Co*Xxx* functions in all subsequent calls concerning this SAP until the client calls
**NdisClDeregisterSap**.

Usually, a client calls
**NdisClRegisterSap** from its
*ProtocolAfRegisterNotify* function following its successful call to
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex).
Registering one or more SAPs allows the client to receive its incoming call(s) as soon as the call
manager receives them over the network.

By contrast with client-initiated outgoing calls, a client does not call
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) before it calls
**NdisClRegisterSap**. For incoming calls, the call manager initiates the creation of the VC, as
follows:

* On receipt of an incoming call on a registered SAP, the call manager first calls
  **NdisCoCreateVc**, causing NDIS to call the client's
  [ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.
* When the VC has been set up and activated, the call manager calls
  [NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall),
  causing NDIS to call the client's
  [ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function.

## See also

[CO_SAP](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545392(v=vs.85))

[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolClRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_register_sap_complete)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)