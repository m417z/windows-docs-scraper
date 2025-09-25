# MI_DestinationOptions_GetProxyType function

## Description

Gets the proxy type set by the user.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `proxyType`

A pointer to a null-terminated string containing the returned proxy type. This string can be one of these values:

#### MI_DESTINATIONOPTIONS_PROXY_TYPE_IE ("IE")

Default IE settings.

#### MI_DESTINATIONOPTIONS_PROXY_TYPE_WINHTTP ("WinHTTP")

WinHTTP settings.

#### MI_DESTINATIONOPTIONS_PROXY_TYPE_AUTO ("Auto")

(Default setting) Provider selects the best option.

#### MI_DESTINATIONOPTIONS_PROXY_TYPE_NONE ("None")

Disables proxy usage.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.