## Description

The **WWAN_SET_PROVISIONED_CONTEXT_V2** structure represents a provisioned context that is supported by a mobile broadband (MBB) device. This structure is used by the [**NDIS_WWAN_SET_PROVISIONED_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_set_provisioned_context_v2) structure.

## Members

### `basicInfo`

A [**WWAN_SET_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context) structure that represents the basic information for this provisioned context.

### `Operation`

A [**WWAN_CONTEXT_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_operations) value that specifies the types of operation used in this Set command.

### `IPType`

A [**WWAN_IP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_ip_type) value that specifies the supported IP types for this provisioned context.

### `Enable`

A [**WWAN_CONTEXT_ENABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_enable) value that specifies whether the context is enabled or disabled in the modem.

### `Roaming`

A [**WWAN_CONTEXT_ROAMING_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_roaming_control) value that specifies which roaming condition applies to this context.

### `MediaType`

A [**WWAN_CONTEXT_MEDIA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_media_type) value that specifies the supported media types for this provisioned context.

### `Source`

A [**WWAN_CONFIGURATION_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_configuration_source) value that specifies the creation source of the context.

### `Reserved`

Reserved for system use. Miniport drivers should not read or write to this value.

### `Snssai`

A [**WWAN_SINGLE_NSSAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_nssai) structure representing a single Network Slice Selection Assistance Information (NSSAI).

## Remarks

## See also

[**WWAN_SET_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context)

[**WWAN_CONTEXT_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_operations)

[**WWAN_IP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_ip_type)

[**WWAN_CONTEXT_ENABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_enable)

[**WWAN_CONTEXT_ROAMING_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_roaming_control)

[**WWAN_CONTEXT_MEDIA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_media_type)

[**WWAN_CONFIGURATION_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_configuration_source)

[**WWAN_SINGLE_NSSAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_nssai)

[**NDIS_WWAN_SET_PROVISIONED_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_set_provisioned_context_v2)