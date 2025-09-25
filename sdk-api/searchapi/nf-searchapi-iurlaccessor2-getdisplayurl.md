# IUrlAccessor2::GetDisplayUrl

## Description

Gets the user-friendly path for the URL item.

## Parameters

### `wszDocUrl` [out]

Type: **WCHAR[]**

Receives the display URL as a null-terminated Unicode string.

### `dwSize` [in]

Type: **DWORD**

Size in **TCHAR****s** of *wszDocUrl*.

### `pdwLength` [out]

Type: **DWORD***

Receives a pointer to the number of
**TCHAR****s** written
to *wszDocUrl*, not including the terminating **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Protocol handlers can reveal hierarchical or non-hierarchical stores. If the data store is organized hierarchically, users can scope their searches to a specified container object like a directory or folder.