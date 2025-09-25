# IRDPViewerInputSink::SendMouseButtonEvent

## Description

[The [IRDPViewerInputSink](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerinputsink) interface is no longer available for use for UWP applications as of Windows 10, version 1709. It is still supported for Desktop apps.]

Sends a mouse button event message.

## Parameters

### `buttonType` [in]

The button that is pressed or released.

### `vbButtonDown` [in]

The button state: **TRUE** if the button is down and **FALSE** otherwise.

### `xPos` [in]

The mouse position in pixels along the horizontal axis.

### `yPos` [in]

The mouse position in pixels along the vertical axis.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPViewerInputSink](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerinputsink)