# IOleInPlaceSiteWindowless::SetFocus

## Description

Sets the keyboard focus for a UI-active, windowless object.

## Parameters

### `fFocus` [in]

If **TRUE**, sets the keyboard focus to the calling object. If **FALSE**, removes the keyboard focus from the calling object, provided that the object has the focus.

## Return value

This method returns S_OK if the keyboard focus was successfully given to the object. If this method is called to release the focus, it should never fail. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Keyboard focus was denied to the object. |

## Remarks

A windowless object calls this method whenever a windowed object would call the [SetFocus](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-setfocus) function. Through this call, the windowless object obtains the keyboard focus and can respond to window messages. Normally, this call is made during the UI activation process and within the notification methods [IOleInPlaceActiveObject::OnDocWindowActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-ondocwindowactivate) with **TRUE** and [IOleInPlaceActiveObject::OnFrameWindowActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-onframewindowactivate) with **TRUE**.

In response to this call, the container sets the Windows focus to the window being used to get keyboard messages (usually the container window) and redirects any subsequent keyboard messages to the windowless object that requested the focus.

A windowless object also calls the **IOleInPlaceSiteWindowless::SetFocus** method with the *fFocus* parameter set to **FALSE** to release the keyboard focus without assigning it to any other object. In this case, the container must call the [SetFocus](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-setfocus) function with a **NULL** parameter so that no window has the focus.

## See also

[IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject)

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)