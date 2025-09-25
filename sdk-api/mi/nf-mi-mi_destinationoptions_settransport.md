# MI_DestinationOptions_SetTransport function

## Description

Sets the transport to be used to communicate with the destination machine.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `transport`

A null-terminated string that represents the transport setting. The value can be any of these constants.

#### MI_DESTINATIONOPTIONS_TRANSPORT_HTTP ("HTTP")

HTTP protocol. Even with HTTP, some authentication schemes allow the payload to be encrypted using the authentication token. Some examples of this include Kerberos, Negotiate, and CredSSP. However, HTTP headers will still be in plain text.

#### MI_DESTINATIONOPTIONS_TRANPSORT_HTTPS ("HTTPS")

HTTPS protocol where the channel is encrypted. Note the misspelling of "TRANPSORT".

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Not all protocols allow different underlying transports to be selected. If not supported, this setting will be ignored.

## See also

[MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions)

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions)

[MI_DestinationOptions_GetTransport](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_gettransport)