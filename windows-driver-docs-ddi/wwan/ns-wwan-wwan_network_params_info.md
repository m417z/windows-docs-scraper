## Description

The **WWAN_NETWORK_PARAMS_INFO** structure represents network configuration data and policy information. Miniport drivers use this structure with [**NDIS_WWAN_NETWORK_PARAMS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_network_params_info) and [NDIS_STATUS_WWAN_NETWORK_PARAMS_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-network-params-state) notifications to notify the host of network parameter updates.

## Members

### `CurrentMicoIndication`

Indicates the current use of Mobile Initiated Connection (MICO) mode. Valid only if NetworkConfigurationsNeeded is 1 in the query request.

### `CurrentDRXParams`

Valid only if NetworkConfigurationsNeeded is 1 in the query request.

### `TaiList`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. The first 4 bytes are the offset to the **DataBuffer** containing a [**WWAN_TAI_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list), in bytes, calculated from the beginning of **WWAN_NETWORK_PARAMS_INFO**. The second 4 bytes are the size of **WWAN_TAI_LIST**, in bytes.

### `AllowedNssaiList`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. The first 4 bytes are the offset to the **DataBuffer** containing a [**WWAN_SNSSAI_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_snssai_list), in bytes, calculated from the beginning of **WWAN_NETWORK_PARAMS_INFO**. The second 4 bytes are the size of **WWAN_SNSSAI_LIST**, in bytes.

### `ConfiguredNssaiList`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. The first 4 bytes are the offset to the **DataBuffer** containing a [**WWAN_SNSSAI_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_snssai_list), in bytes, calculated from the beginning of **WWAN_NETWORK_PARAMS_INFO**. The second 4 bytes are the size of **WWAN_SNSSAI_LIST**, in bytes.

### `RejectedNssaiList`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. The first 4 bytes are the offset to the **DataBuffer** containing a [**WWAN_REJECTED_SNSSAI_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_rejected_snssai_list), in bytes, calculated from the beginning of **WWAN_NETWORK_PARAMS_INFO**. The second 4 bytes are the size of **WWAN_REJECTED_SNSSAI_LIST**, in bytes.

### `DefaultConfiguredNssaiList`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. The first 4 bytes are the offset to the **DataBuffer** containing a [**WWAN_SNSSAI_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_snssai_list), in bytes, calculated from the beginning of **WWAN_NETWORK_PARAMS_INFO**. The second 4 bytes are the size of **WWAN_SNSSAI_LIST**, in bytes.

### `LadnList`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. The first 4 bytes are the offset to the **DataBuffer** containing a [**WWAN_LADN_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_ladn_list), in bytes, calculated from the beginning of **WWAN_NETWORK_PARAMS_INFO**. The second 4 bytes are the size of **WWAN_LADN_LIST**, in bytes.

### `DataBuffer`

A buffer containing **TaiList**, **AllowedNssaiList**, **ConfiguredNssaiList**, **RejectedNssaiList**, **DefaultConfiguredNssaiList**, and **LadnList** immediately follow the last named field of **WWAN_NETWORK_PARAMS_INFO** (**LadnList**), in that order, without any unused space in between.

## Remarks

## See also

[NDIS_STATUS_WWAN_NETWORK_PARAMS_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-network-params-state)

[**NDIS_WWAN_NETWORK_PARAMS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_network_params_info)