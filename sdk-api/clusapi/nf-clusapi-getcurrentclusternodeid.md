## Description

Returns the unique identifier of the current cluster [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes).

## Parameters

### `_lpszNodeId_` [out]

This parameter points to a buffer that receives the unique ID of *hNode*, including the terminating **NULL** character.

### `_lpcchName_` [in, out]

On input, pointer to the count of characters in the buffer pointed to by the *lpszNodeId* parameter, including the **NULL** terminator. On output, pointer to the count of characters stored in the buffer excluding the **NULL** terminator.

## Remarks

Note that *_lpcchName_* refers to a count of characters and not a count of bytes, and that the returned size does not include the terminating **NULL** in the count. For more information on sizing buffers, see [Data size conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

## See also

[GetClusterNodeId](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-getclusternodeid)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)

[OpenClusterNode](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-openclusternode)

## Syntax

```cpp
DWORD GetCurrentClusterNodeId(
  [out]      LPWSTR _lpszNodeId,
  [in, out]  LPDWORD _lpcchName_
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

This function returns a [system error code](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following are the possible values:

- **ERROR_SUCCESS**
  - 0 (0x0)
  - The operation completed successfully.
- **ERROR_MORE_DATA**
  - 234 (0xEA)
  - More data is available.
  - This value is returned if the buffer pointed to by _\_lpszNodeId_\_ is not long enough to hold the required number of characters. **GetCurrentClusterNodeId** sets the content of _\_lpcchName_\_ to the required length.