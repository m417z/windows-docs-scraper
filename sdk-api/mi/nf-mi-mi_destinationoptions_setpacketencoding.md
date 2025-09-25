# MI_DestinationOptions_SetPacketEncoding function

## Description

Sets the encoding mechanism for certain protocol handles.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `encoding`

A null-terminated string representing one of the following encoding mechanism values.

#### MI_DESTINATIONOPTIONS_PACKET_ENCODING_DEFAULT ("default")

Transport-specific default encoding per the WinRM protocol handler.

#### MI_DESTINATIONOPTIONS_PACKET_ENCODING_UTF8 ("UTF8")

UTF-8 encoding.

#### MI_DESTINATIONOPTIONS_PACKET_ENCODING_UTF16 ("UTF16")

UTF-16 encoding.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions)

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions)

[MI_DestinationOptions_GetPacketEncoding](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getpacketencoding)

[Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal)