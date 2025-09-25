# MI_DestinationOptions_SetProxyType function

## Description

Sets the type of proxy settings to use when communicating to a destination through a proxy.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `proxyType`

A null-terminated string that represents the proxy mechanism to use. Possible values include these constants.

#### MI_DESTINATIONOPTIONS_PROXY_TYPE_IE ("IE")

Default IE settings.

#### MI_DESTINATIONOPTIONS_PROXY_TYPE_WINHTTP ("WinHTTP")

WinHTTP settings.

#### MI_DESTINATIONOPTIONS_PROXY_TYPE_AUTO ("Auto")

(Default setting) Provider selects the best option.

#### MI_DESTINATIONOPTIONS_PROXY_TYPE_NONE ("None")

Disables proxy usage.

## Remarks

Not all protocols and transports support proxy configurations. The defaults for this setting will vary depending on the protocol and transport selected.

## See also

[MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions)

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions)

[MI_DestinationOptions_GetProxyType](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getproxytype)