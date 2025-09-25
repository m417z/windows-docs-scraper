# NdisCmOpenAddressFamilyComplete function

## Description

**NdisCmOpenAddressFamilyComplete** returns the final status of a stand-alone call manager's open of a
given AF for a particular client after the call manager returned NDIS_STATUS_PENDING in response to that
client's original open-AF request.

## Parameters

### `Status` [in]

Specifies the final status of the open-AF operation, either NDIS_STATUS_SUCCESS or any
CM-determined error NDIS_STATUS_
*XXX* except NDIS_STATUS_PENDING.

### `NdisAfHandle` [in]

Specifies the NDIS-supplied handle that was input to the call manager's
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function, which
returned NDIS_STATUS_PENDING.

### `CallMgrAfContext` [in]

Specifies the handle to a caller-allocated resident context area in which the call manager
maintains state about this client's open of the address family, including the
*NdisAfHandle*, if the open succeeded. If
*Status* is not NDIS_STATUS_SUCCESS, NDIS ignores this parameter.

## Remarks

A stand-alone call manager must call
**NdisCmOpenAddressFamilyComplete** if its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function previously
returned NDIS_STATUS_PENDING for the given
*NdisAfHandle* . The client, which initiated the pended open-AF operation with a call to
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex),
cannot carry out further connection-oriented operations on the same binding until
**NdisCmOpenAddressFamilyComplete** causes a call to that client's
[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex) function.

If the caller of
**NdisCmOpenAddressFamilyComplete** sets
*Status* to NDIS_STATUS_SUCCESS, NDIS subsequently passes the given
*CallMgrAfContext* handle as an input parameter to all CM-supplied ProtocolCm*Xxx* and ProtocolCo*Xxx* functions that concern the client's open of the address family until the client closes the AF.
The call manager should release or reuse any AF context area that it allocated before it passes a failure
status to
**NdisCmOpenAddressFamilyComplete**.

For a successful open, the NDIS-supplied
*NdisAfHandle* represents an association between the call manager and client for the opened AF on a
particular miniport driver to which the call manager and client are bound. Both protocol drivers must
treat
*NdisAfHandle* as an opaque variable to be passed, unmodified and uninterpreted, in subsequent calls
to NdisCl/Cm/CoXxx functions for which this handle is a required parameter. For a failed open, the call
manager should consider the
*NdisAfHandle* invalid when
**NdisMCmOpenAddressFamilyComplete** returns control.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmOpenAddressFamilyComplete**. Connection-oriented miniport drivers that provide integrated
call-management support must call
[NdisMCmOpenAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmopenaddressfamilycomplete) instead.

## See also

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisMCmOpenAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmopenaddressfamilycomplete)

[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)