# IExplorerBrowser::GetCurrentView

## Description

Gets an interface for the current view of the browser.

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the desired interface ID.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This will typically be [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview), [IShellView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview2), [IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview), or a related interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use the **IID_PPV_ARGS** macro.