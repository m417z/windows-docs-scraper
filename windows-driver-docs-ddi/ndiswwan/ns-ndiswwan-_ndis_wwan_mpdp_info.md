# _NDIS_WWAN_MPDP_INFO structure

## Description

The **NDIS_WWAN_MPDP_INFO** structure contains information for an operation to perform on a Multiple Packet Data Protocol (MPDP) interface.

## Members

### `Operation`

An [**WWAN_MPDP_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ne-ndiswwan-_wwan_mpdp_operation) value that specifies the operation to perform.

### `ChildInterfaceGUID`

The GUID of the child interface to be deleted, if **Operation** is set to **WwanMPDPOperationDeleteChildInterface**. If **Operation** is set to **WwanMPDPOperationCreateChildInterface**, then this value is the GUID of the newly created child interface.

### `MacAddr`

Currently unused.

## Remarks

This structure is a member of both the [**NDIS_WWAN_SET_MPDP_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_mpdp_state) structure and the [**NDIS_WWAN_MPDP_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_mpdp_state) structure.

## See also

[**WWAN_MPDP_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ne-ndiswwan-_wwan_mpdp_operation)

[**NDIS_WWAN_SET_MPDP_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_mpdp_state)

[**NDIS_WWAN_MPDP_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_mpdp_state)

[OID_WWAN_MPDP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-mpdp)