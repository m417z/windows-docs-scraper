# IRDPSRAPIViewer::RequestControl

## Description

[The [IRDPSRAPIViewer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiviewer) interface is no longer available for use for UWP applications as of Windows 10, version 1709. It is still supported for Desktop apps.]

Requests the sharer to change the control level of the viewer. After this method is called, a message is sent to the sharer to notify the sharer that a viewer is requesting a control level change. After the sharer receives the message, an event is raised on the sharer side to notify the application that an attendee is requesting a change in control level. The application or user can then decide whether to allow the requested level of control for an attendee.

## Parameters

### `CtrlLevel` [in]

Type: **CTRL_LEVEL**

One of the values of the [CTRL_LEVEL](https://learn.microsoft.com/windows/win32/api/rdpencomapi/ne-rdpencomapi-ctrl_level) enumeration.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPIViewer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiviewer)