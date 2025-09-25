# IOleControlSite::TranslateAccelerator

## Description

Passes a keystroke to the control site for processing.

## Parameters

### `pMsg` [in]

A pointer to the [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure describing the keystroke to be processed.

### `grfModifiers` [in]

Flags describing the state of the Control, Alt, and Shift keys. The value of the flag can be any valid [KEYMODIFIERS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683763(v=vs.85)) enumeration values.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The container processed the message. |
| **S_FALSE** | The container did not process the message. This value must also be returned in all other error cases besides E_NOTIMPL. |
| **E_NOTIMPL** | The container does not implement accelerator support. |

## Remarks

This method is called by a control that can be UI-active. In such cases, a control can process all keystrokes first through [IOleInPlaceActiveObject::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-translateaccelerator), according to normal OLE Compound Document rules. Inside that method, the control can give the container certain messages to process first by calling **IOleControlSite::TranslateAccelerator** and using the return value to determine if any processing took place. Otherwise, the control always processes the message first. If the control does not use the keystroke as an accelerator, it passes the keystroke to the container through this method.

## See also

[IOleControlSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite)

[IOleInPlaceActiveObject::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-translateaccelerator)