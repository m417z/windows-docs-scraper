# IRDPViewerInputSink::SendKeyboardEvent

## Description

[The [IRDPViewerInputSink](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerinputsink) interface is no longer available for use for UWP applications as of Windows 10, version 1709. It is still supported for Desktop apps.]

Sends a keyboard event message.

## Parameters

### `codeType`

The encoding of the key code.

### `keycode`

The key code of the pressed or released key.

### `vbKeyUp`

The state of the key: **TRUE** if the key is released, **FALSE** if the key is pressed.

### `vbRepeat`

The key code is a repeated code: **FALSE** if this is the initial key code from a key press, **TRUE** if this is repeated code from a single key press.

### `vbExtended`

The key code is extended: **TRUE** if the code is extended, **FALSE** otherwise.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPViewerInputSink](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerinputsink)