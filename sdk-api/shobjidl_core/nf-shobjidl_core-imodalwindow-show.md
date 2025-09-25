# IModalWindow::Show

## Description

Launches the modal window.

## Parameters

### `hwndOwner` [in, optional]

Type: **HWND**

The handle of the owner window. This value can be **NULL**.

## Return value

Type: **HRESULT**

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code, including the following:

| Return code | Description |
| --- | --- |
| **[HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32)(ERROR_CANCELLED)** | The user closed the window by cancelling the operation. |