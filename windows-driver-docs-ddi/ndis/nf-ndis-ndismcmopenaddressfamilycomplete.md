# NdisMCmOpenAddressFamilyComplete macro

## Description

**NdisMCmOpenAddressFamilyComplete** returns the final status of a client's request, for which the MCM
driver's
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function returned
NDIS_STATUS_PENDING, to open the MCM driver's address family.

## Parameters

### `_S_`

Specifies the final status of the client's request to open the AF, either NDIS_STATUS_SUCCESS or
any caller-determined NDIS_STATUS_
*XXX* except NDIS_STATUS_PENDING.

### `_H_`

Specifies the NDIS-supplied handle that was input to the MCM driver's
*ProtocolCmOpenAf* function, which returned NDIS_STATUS_PENDING.

### `_C_`

Specifies the handle to a caller-allocated resident context area, in which the MCM driver
maintains state about this client's open of the address family, including the
*NdisAfHandle*, if the open succeeded. Otherwise, NDIS ignores this parameter.

## Remarks

An MCM driver must call
**NdisMCmOpenAddressFamilyComplete** if its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function previously
returned NDIS_STATUS_PENDING for the given
*NdisAfHandle* . The client, which initiated the pended open-AF operation with a call to
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex),
cannot carry out further connection-oriented operations on the same binding until
**NdisMCmOpenAddressFamilyComplete** causes a call to that client's
[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex) function.

If the caller of
**NdisMCmOpenAddressFamilyComplete** sets
*Status* to NDIS_STATUS_SUCCESS, NDIS subsequently passes the given
*CallMgrAfContext* handle as an input parameter to all MCM driver-supplied ProtocolCm*Xxx* and ProtocolCo*Xxx* functions that concern the client's open of the address family until the client closes the AF.
The MCM driver should release or reuse any AF context area that it allocated before it passes a failure
status to
**NdisMCmOpenAddressFamilyComplete**.

For a successful open, the NDIS-supplied
*NdisAfHandle* represents an association between the MCM driver and client for the opened AF. Both
NDIS drivers must treat
*NdisAfHandle* as an opaque variable to be passed, unmodified and uninterpreted, in subsequent calls
to NdisCl/Co/MCm/MCoXxx functions for which this handle is a required parameter. For a failed open, the
MCM driver should consider the
*NdisAfHandle* invalid when
**NdisMCmOpenAddressFamilyComplete** returns control.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmOpenAddressFamilyComplete**. Stand-alone call managers, which register themselves with NDIS
as protocol drivers, call
**NdisCmOpenAddressFamilyComplete** instead.

## See also

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisCmOpenAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmopenaddressfamilycomplete)

[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)