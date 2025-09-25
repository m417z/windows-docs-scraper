# NdisCmCloseAddressFamilyComplete function

## Description

**NdisCmCloseAddressFamilyComplete** returns the final status of a client's request, for which the CM's
[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af) function returned
NDIS_STATUS_PENDING, to close the AF.

## Parameters

### `Status` [in]

The call manager sets this to NDIS_STATUS_SUCCESS.

### `NdisAfHandle` [in]

Specifies the NDIS-supplied handle passed to the call manager's
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function when this
client originally opened the address family.

## Remarks

A stand-alone call manager must call
**NdisCmCloseAddressFamilyComplete** if its
[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af) function previously
returned NDIS_STATUS_PENDING for the given
*NdisAfHandle* . The client, which initiated the pended close-AF operation with a call to
[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily), cannot
release the resources it allocated to track communications on the AF until the CM's call to
**NdisCmCloseAddressFamilyComplete** causes a call to that client's
[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete) function.

After a call to
**NdisCmCloseAddressFamilyComplete**, the call manager cannot subsequently use the
*NdisAfHandle*, which becomes invalid for the call manager as soon as this call occurs.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmCloseAddressFamilyComplete**. Connection-oriented miniport drivers that provide integrated
call-management support must call
**NdisMCmCloseAddressFamilyComplete** instead.

## See also

[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily)

[NdisMCmCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcloseaddressfamilycomplete)

[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete)

[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)