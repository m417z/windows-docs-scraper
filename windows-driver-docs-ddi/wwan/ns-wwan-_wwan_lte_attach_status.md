# _WWAN_LTE_ATTACH_STATUS structure

## Description

The **WWAN_LTE_ATTACH_STATUS** structure describes the last used default LTE attach context for a mobile broadband (MBB) modem.

## Members

### `LteAttachState`

A [**WWAN_CONTEXT_LTE_ATTACH_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_lte_attach_state) value that indicates whether the device is currently attach to an LTE network or not.

### `IPType`

A [**WWAN_IP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_ip_type) value that specifies the supported IP types for the default LTE attach context.

### `basicInfo`

A [**WWAN_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context) structure that represents the basic information for the default LTE attach context.

### `NetworkError`

## Remarks

This structure is used in the [**NDIS_WWAN_LTE_ATTACH_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_lte_attach_status) structure.

## See also

[MB LTE Attach Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-lte-attach-operations)

[**NDIS_WWAN_LTE_ATTACH_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_lte_attach_status)