# OleSetMenuDescriptor function

## Description

Installs or removes OLE dispatching code from the container's frame window.

## Parameters

### `holemenu` [in]

Handle to the composite menu descriptor returned by the [OleCreateMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatemenudescriptor) function. If **NULL**, the dispatching code is unhooked.

### `hwndFrame` [in]

 Handle to the container's frame window where the in-place composite menu is to be installed.

### `hwndActiveObject` [in]

Handle to the object's in-place activation window. OLE dispatches menu messages and commands to this window.

### `lpFrame` [in]

Pointer to the [IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe) interface on the container's frame window.

### `lpActiveObj` [in]

Pointer to the [IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject) interface on the active in-place object.

## Return value

This function returns S_OK on success.

## Remarks

The container should call **OleSetMenuDescriptor** to install the dispatching code on *hwndFrame* when the object calls the [IOleInPlaceFrame::SetMenu](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-setmenu) method, or to remove the dispatching code by passing **NULL** as the value for *holemenu* to **OleSetMenuDescriptor**.

If both the *lpFrame* and *lpActiveObj* parameters are non-**NULL**, OLE installs the context-sensitive help F1 message filter for the application. Otherwise, the application must supply its own message filter.

## See also

[IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject)

[IOleInPlaceFrame::SetMenu](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-setmenu)

[OleCreateMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatemenudescriptor)