# _WWAN_CONTEXT_V2 structure

## Description

The **WWAN_CONTEXT_V2** structure represents a provisioned context that is supported by a mobile broadband (MBB) device. This structure extends the existing [**WWAN_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context) structure.

## Members

### `basicInfo`

A [**WWAN_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context) structure that represents the basic information for this provisioned context.

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

## Remarks

**WWAN_CONTEXT_V2** is used as a response to Query or Set requests, unlike [**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2) which is used for Set requests.

## See also

[**WWAN_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context)

[**WWAN_IP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_ip_type)

[**WWAN_CONTEXT_ENABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_enable)

[**WWAN_CONTEXT_ROAMING_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_roaming_control)

[**WWAN_CONTEXT_MEDIA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_context_media_type)

[**WWAN_CONFIGURATION_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_configuration_source)

[**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2)