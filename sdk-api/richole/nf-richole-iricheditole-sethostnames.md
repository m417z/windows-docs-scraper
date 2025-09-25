# IRichEditOle::SetHostNames

## Description

Sets the host names to be given to objects as they are inserted to a rich edit control. The host names are used in the user interface of servers to describe the container context of opened objects.

## Parameters

### `lpstrContainerApp`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Null-terminated name of the container application.

### `lpstrContainerObj`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Null-terminated name of the container document or object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise. E_OUTOFMEMORY is returned if memory could not be allocated to remember the strings.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)