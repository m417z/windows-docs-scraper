# IBrowserService2::GetViewWindow

## Description

Deprecated. Provides direct access to the browser view window created by [IBrowserService2::CreateViewWindow](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice2-createviewwindow).

## Parameters

### `phwndView` [out]

Type: **HWND***

A pointer to the handle of the browser window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IBrowserService2::GetViewWindow** retrieves the same handle as found in the **_hwndView** member of the [BASEBROWSERDATA](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ns-shdeprecated-basebrowserdatalh) structure. This method simply provides direct access to that view, bypassing the need to access the **BASEBROWSERDATA** structure though a method such as [IBrowserService2::GetBaseBrowserData](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice2-getbasebrowserdata).