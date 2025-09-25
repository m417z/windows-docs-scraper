# NdisCmRegisterSapComplete function

## Description

**NdisCmRegisterSapComplete** returns the final status of a client's request, for which the CM previously
returned NDIS_STATUS_PENDING, to register a SAP.

## Parameters

### `Status` [in]

Specifies the final status of the client's original request to register the SAP, either
NDIS_STATUS_SUCCESS or any CM-determined NDIS_STATUS_*XXX* except NDIS_STATUS_PENDING.

### `NdisSapHandle` [in]

Specifies the NDIS-supplied handle to the SAP if the registration is successful. The call manager
obtained this handle as an input parameter to its
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function.

### `CallMgrSapContext` [in]

Specifies the handle to a caller-supplied resident context area in which the CM maintains state
for this SAP if the registration is successful. If so, NDIS passes this handle back to the CM in all
subsequent calls concerning this SAP. If
*Status* is set to something other than NDIS_STATUS_SUCCESS, NDIS ignores this parameter.

## Remarks

A stand-alone call manager must call
**NdisCmRegisterSapComplete** if its
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function
returned NDIS_STATUS_PENDING when it was called with the given
*NdisSapHandle* . The call to
**NdisCmRegisterSapComplete** causes NDIS to call the client's
[ProtocolClRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_register_sap_complete) function.

If the call manager sets
*Status* to anything other than NDIS_STATUS_SUCCESS, it should consider the
*NdisSapHandle* invalid as soon as it calls
**NdisCmRegisterSapComplete**. After failing a SAP registration, the CM can release or reuse the
per-SAP context area that it allocated when
**NdisCmRegisterSapComplete** returns control. NDIS also releases its context for the SAP if the call
manager fails the registration.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmRegisterSapComplete**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmRegisterSapComplete**.

## See also

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisMCmRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmregistersapcomplete)

[ProtocolClRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_register_sap_complete)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)