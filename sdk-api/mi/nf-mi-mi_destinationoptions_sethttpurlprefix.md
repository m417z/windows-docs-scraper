# MI_DestinationOptions_SetHttpUrlPrefix function

## Description

Set the default HTTP URL prefix for transports that go over HTTP and HTTPS.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `prefix`

A null-terminated string that represents the HTTP URL prefix ("HTTP" or "HTTPS").

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

The default URL prefix is protocol specific. This setting is ignored by transports that do not support this.

## See also

[MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions)

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions)

[MI_DestinationOptions_GetHttpUrlPrefix](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_gethttpurlprefix)

[MI_DestinationOptions_GetTransport](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_gettransport)

[MI_DestinationOptions_SetTransport](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_settransport)