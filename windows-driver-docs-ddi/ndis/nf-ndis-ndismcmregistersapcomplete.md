# NdisMCmRegisterSapComplete macro

## Description

**NdisMCmRegisterSapComplete** returns the final status of a client's request, for which the MCM driver's
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function
previously returned NDIS_STATUS_PENDING, to register a SAP.

## Parameters

### `_S_`

Specifies the final status for the client's original request to register the SAP, either
NDIS_STATUS_SUCCESS or any caller-determined NDIS_STATUS_*XXX*except NDIS_STATUS_PENDING.

### `_H_`

Specifies the NDIS-supplied handle to the SAP if the registration is successful. The call manager
obtained this handle as an input parameter to its
*ProtocolCmRegisterSap* function.

### `_C_`

Specifies the handle to a caller-supplied resident context area in which the MCM driver maintains
state for this SAP if the registration is successful. If so, NDIS passes this handle back to the to the
MCM driver in all subsequent calls concerning this SAP. If
*Status* is set to something other than NDIS_STATUS_SUCCESS, NDIS ignores this parameter.

## Remarks

An MCM driver must call
**NdisMCmRegisterSapComplete** if its
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function
returned NDIS_STATUS_PENDING when it was called with the given
*NdisSapHandle* . The call to
**NdisMCmRegisterSapComplete** causes NDIS to call the client's
[ProtocolClRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_register_sap_complete) function.

If the MCM driver sets
*Status* to anything other than NDIS_STATUS_SUCCESS, it should consider the
*NdisSapHandle* invalid when
**NdisMCmRegisterSapComplete** returns control. After failing a SAP registration, the CM can release or
reuse the per-SAP context area, if any, that it already allocated. NDIS also releases its context for the
SAP if the MCM driver fails the registration.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmRegisterSapComplete**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmRegisterSapComplete** instead.

## See also

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregistersapcomplete)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[ProtocolClRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_register_sap_complete)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)