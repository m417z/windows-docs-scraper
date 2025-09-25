# IUrlAccessor::GetHost

## Description

Gets the host name for the content source, if applicable.

## Parameters

### `wszHost` [out]

Type: **WCHAR[]**

Receives the name of the host that the content source file resides on, as a null-terminated Unicode string.

### `dwSize` [in]

Type: **DWORD**

Size in **TCHAR****s** of *wszHost*, not including the terminating **NULL**.

### `pdwLength` [out]

Type: **DWORD***

Receives a pointer to the number of **TCHAR****s** written to *wszHost*, not including the terminating **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.