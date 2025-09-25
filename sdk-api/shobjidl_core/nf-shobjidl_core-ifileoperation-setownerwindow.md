# IFileOperation::SetOwnerWindow

## Description

Sets the parent or owner window for progress and dialog windows.

## Parameters

### `hwndOwner` [in]

Type: **HWND**

A handle to the owner window of the operation. This window will receive error messages.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.