# OleTranslateAccelerator function

## Description

Called by the object application, allows an object's container to translate accelerators according to the container's accelerator table.

## Parameters

### `lpFrame` [in]

Pointer to the [IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe) interface to which the keystroke might be sent.

### `lpFrameInfo` [in]

Pointer to an [OLEINPLACEFRAMEINFO](https://learn.microsoft.com/windows/win32/api/oleidl/ns-oleidl-oleinplaceframeinfo) structure containing the accelerator table obtained from the container.

### `lpmsg` [in]

Pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure containing the keystroke.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The object should continue processing this message. |

## Remarks

Object servers call **OleTranslateAccelerator** to allow the object's container to translate accelerator keystrokes according to the container's accelerator table, pointed to by *lpFrameInfo*. While a contained object is the active object, the object's server always has first chance at translating any messages received. If this is not desired, the server calls **OleTranslateAccelerator** to give the object's container a chance. If the keyboard input matches an accelerator found in the container-provided accelerator table, **OleTranslateAccelerator** passes the message and its command identifier on to the container through the [IOleInPlaceFrame::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-translateaccelerator) method. This method returns S_OK if the keystroke is consumed; otherwise it returns S_FALSE.

Accelerator tables for containers should be defined so they will work properly with object applications that do their own accelerator keystroke translations. These tables should take the form:

``` syntax
"char", wID, VIRTKEY, CONTROL
```

This is the most common way to describe keyboard accelerators. Failure to do so can result in keystrokes being lost or sent to the wrong object during an in-place session.

Objects can call the [IsAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-isaccelerator) function to see whether the accelerator keystroke belongs to the object or the container.

## See also

[IOleInPlaceFrame::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-translateaccelerator)

[IsAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-isaccelerator)