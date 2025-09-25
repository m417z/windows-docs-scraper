# GetCIMSSM function

## Description

[**GetCIMSSM** may be altered or unavailable in the future. Instead, use [GetCurrentInputMessageSource](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcurrentinputmessagesource).]

Retrieves the source of the input message (GetCurrentInputMessageSourceInSendMessage).

## Parameters

### `inputMessageSource` [out]

The [INPUT_MESSAGE_SOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input_message_source) structure that holds the device type and the ID of the input message source.

## Return value

If this function succeeds, it returns TRUE. Otherwise, it returns ERROR_INVALID_PARAMETER.

This function fails when:

* The input parameter is invalid.
* [GetCurrentInputMessageSource](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcurrentinputmessagesource) returns a value other than [IMDT_UNAVAILABLE](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-input_message_device_type) for the device type.

## Remarks

**GetCIMSSM** should be used only when [GetCurrentInputMessageSource](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcurrentinputmessagesource) returns a device type of [IMDT_UNAVAILABLE](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-input_message_device_type).

## See also

[Input Source Identification Reference](https://learn.microsoft.com/previous-versions/windows/desktop/input_sourceid/input-source-identification-reference)