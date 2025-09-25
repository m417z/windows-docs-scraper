# GetCurrentInputMessageSource function

## Description

Retrieves the source of the input message.

## Parameters

### `inputMessageSource` [out]

The [INPUT_MESSAGE_SOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input_message_source) structure that holds the device type and the ID of the input message source.

**Note** **deviceType** in [INPUT_MESSAGE_SOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input_message_source) is set to [IMDT_UNAVAILABLE](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-input_message_device_type) when [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) is used to inject input (system generated or through messages such as [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)). This remains true until **SendMessage** returns.

## Return value

If this function succeeds, it returns TRUE. Otherwise, it returns FALSE. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[Input Source Identification Reference](https://learn.microsoft.com/previous-versions/windows/desktop/input_sourceid/input-source-identification-reference)