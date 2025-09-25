# IOleInPlaceUIWindow::SetActiveObject

## Description

Provides a direct channel of communication between the object and each of the frame and document windows.

## Parameters

### `pActiveObject` [in]

A pointer to the [IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject) interface on the active in-place object.

### `pszObjName` [in]

A pointer to a string containing a name that describes the object an embedding container can use in composing its window title. It can be **NULL** if the object does not require the container to change its window titles. Containers should ignore this parameter and always use their own name in the title bar.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

Generally, an embedded object should pass **NULL** for the *pszObjName* parameter (see Notes to Implementers below). However, if you are working in conjunction with a container that does display the name of the in-place active object in its title bar, then you should compose a string in the following form: <*application name*> – <*object short-type name*>.

### Notes to Callers

**IOleInPlaceUIWindow::SetActiveObject** is called by the object to establish a direct communication link between itself and the document and frame windows.

When deactivating, the object calls **IOleInPlaceUIWindow::SetActiveObject**, passing **NULL** for the *pActiveObject* and pszObjName parameters.

An object must call **IOleInPlaceUIWindow::SetActiveObject** before calling [IOleInPlaceFrame::SetMenu](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-setmenu) to give the container the pointer to the active object. The container then uses this pointer in processing **IOleInPlaceFrame::SetMenu** and to pass to [OleSetMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor).

### Notes to Implementers

The Microsoft Windows User Interface Design Guide recommends that an in-place container ignore the *pszObjName* parameter passed in this method. The guide says "The title bar is not affected by in-place activation. It always displays the top-level container's name."

## See also

[IOleInPlaceFrame::SetMenu](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-setmenu)

[IOleInPlaceUIWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceuiwindow)

[OleSetMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor)