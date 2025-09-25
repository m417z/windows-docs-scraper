# IExplorerBrowser::Destroy

## Description

Destroys the browser.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If method [IExplorerBrowser::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-initialize) was called., then method **IExplorerBrowser::Destroy** must be called to free resources. Failure to call **IExplorerBrowser::Destroy** may cause a memory leak.