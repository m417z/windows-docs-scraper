# IDockingWindowFrame::FindToolbar

## Description

Finds the specified [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object in the toolbar frame and returns an interface pointer to it.

## Parameters

### `pwszItem` [in]

Type: **PCWSTR**

A pointer to a null-terminated, Unicode, application-defined string used to identify the object. This is the same string that was passed to the [AddToolbar](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-idockingwindowframe-addtoolbar) method.

### `riid` [in]

Type: **REFIID**

A reference to the desired interface ID. This is typically IID_IDockingWindow.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow). If an error occurs, this value receives a null pointer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe)

[IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite)