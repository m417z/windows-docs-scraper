# IOleInPlaceFrame::TranslateAccelerator

## Description

Translates accelerator keystrokes intended for the container's frame while an object is active in place.

## Parameters

### `lpmsg` [in]

A pointer to the [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains the keystroke message.

### `wID` [in]

The command identifier value corresponding to the keystroke in the container-provided accelerator table. Containers should use this value instead of translating again.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The keystroke was not used. |
| **E_INVALIDARG** | The specified pointer is invalid. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

### Notes to Callers

The **IOleInPlaceFrame::TranslateAccelerator** method is called indirectly by [OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator) when a keystroke accelerator intended for the container (frame) is received.

### Notes to Implementers

The container application should perform its usual accelerator processing, or use *wID* directly, and then return, indicating whether the keystroke accelerator was processed. If the container is an MDI application and the [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepropertypage-translateaccelerator) function fails, the container can call the [TranslateMDISysAccel](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemdisysaccel) function, just as it does for its usual message processing.

In-place objects should be given first chance at translating accelerator messages. However, because objects implemented by DLL object applications do not have their own message pump, they receive their messages from the container's message queue. To ensure that the object has first chance at translating messages, a container should always call **IOleInPlaceFrame::TranslateAccelerator** before doing its own accelerator translation. Conversely, an executable object application should call [OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator) after calling [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepropertypage-translateaccelerator), calling [TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) and [DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage) only if both translation functions fail.

You should define accelerator tables for containers so they will work properly with object applications that do their own accelerator keystroke translations. Tables should be defined as follows.

``` syntax
"char", wID, VIRTKEY, CONTROL
```

This is the most common way to describe keyboard accelerators. Failure to do so can result in keystrokes being lost or sent to the wrong object during an in-place session.

## See also

[IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe)

[IOleInPlaceFrame::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-translateaccelerator)

[OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator)

[TranslateAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepropertypage-translateaccelerator)

[TranslateMDISysAccel](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemdisysaccel)