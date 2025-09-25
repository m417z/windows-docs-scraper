# IFileDialog::Unadvise

## Description

Removes an event handler that was attached through the [IFileDialog::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-advise) method.

## Parameters

### `dwCookie` [in]

Type: **DWORD**

The **DWORD** value that represents the event handler. This value is obtained through the *pdwCookie* parameter of the [IFileDialog::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-advise) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.