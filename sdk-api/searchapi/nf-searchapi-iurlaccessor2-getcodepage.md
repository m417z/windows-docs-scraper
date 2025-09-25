# IUrlAccessor2::GetCodePage

## Description

Gets the code page for properties of the URL item.

## Parameters

### `wszCodePage` [out]

Type: **WCHAR[]**

Receives the code page as a null-terminated Unicode string.

### `dwSize` [in]

Type: **DWORD**

Size of *wszCodePage*
in **TCHAR****s**.

### `pdwLength` [out]

Type: **DWORD***

Receives a pointer to the number of
**TCHAR****s** written to
*wszCodePage*, not including the terminating **NULL** character.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.