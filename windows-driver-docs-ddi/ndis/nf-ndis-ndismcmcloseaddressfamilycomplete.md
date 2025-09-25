# NdisMCmCloseAddressFamilyComplete macro

## Description

**NdisMCmCloseAddressFamilyComplete** returns the final status of a client's request, for which the MCM
driver returned NDIS_STATUS_PENDING, to close the AF.

## Parameters

### `_S_`

The caller sets this to NDIS_STATUS_SUCCESS.

### `_H_`

Specifies the NDIS-supplied handle passed to the MCM driver's
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function when this
client originally opened the address family.

## Remarks

An MCM driver must call
**NdisMCmCloseAddressFamilyComplete** if its
[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af) function previously
returned NDIS_STATUS_PENDING for the given
*NdisAfHandle* . The client, which initiated the pended close-AF operation with a call to
[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily), cannot
release the resources it allocated to track communications on the AF until the MCM driver's call to
**NdisMCmCloseAddressFamilyComplete**.

A call to
**NdisMCmCloseAddressFamilyComplete** causes NDIS to call the client's
[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete) function.

The MCM driver cannot subsequently use the
*NdisAfHandle*, which is invalid for the MCM driver when
**NdisMCmCloseAddressFamilyComplete** returns control.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmCloseAddressFamilyComplete**. Stand-alone call managers, which register themselves with NDIS
as protocol drivers, call
**NdisCmCloseAddressFamilyComplete** instead.

## See also

[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily)

[NdisCmCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmcloseaddressfamilycomplete)

[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete)

[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)