# IRDPViewerInputSink::AddTouchInput

## Description

[The [IRDPViewerInputSink](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerinputsink) interface is no longer available for use for UWP applications as of Windows 10, version 1709. It is still supported for Desktop apps.]

Accepts a description of a touch input.

## Parameters

### `contactId`

The identifier of the contact that generated the touch input.

### `event`

The event that results from the input.

### `x`

The touch position in the x-axis.

### `y`

The touch position in the y-axis.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[BeginTouchFrame](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpviewerinputsink-begintouchframe)

[EndTouchFrame](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpviewerinputsink-endtouchframe)

[IRDPViewerInputSink](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerinputsink)