# FilterClose function

## Description

The **FilterClose** function closes an open minifilter handle.

## Parameters

### `hFilter` [in]

Minifilter handle returned by a previous call to [FilterCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtercreate).

## Return value

**FilterClose** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

After **FilterClose** is called, the minifilter handle that the *hFilter* parameter specifies is no longer valid and cannot safely be used.

Use **FilterClose** to close open minifilter handles returned by calls to [FilterCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtercreate). Use [FilterFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindclose) to close handles returned by calls to [FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst).

To close a connection port handle that was opened by calling [FilterConnectCommunicationPort](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterconnectcommunicationport), use [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle).

## See also

[CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle)

[FilterConnectCommunicationPort](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterconnectcommunicationport)

[FilterCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtercreate)

[FilterFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindclose)

[FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst)