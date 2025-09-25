## Description

The `AreShortNamesEnabled` function determines whether short names are enabled for the specified volume. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

## Parameters

### `Handle`

The handle to the volume or the handle to a file or directory that resides on the volume to query.

### `Enabled`

A pointer to a `BOOLEAN` value that receives the result of the query. If `TRUE`, short names are enabled for the volume, otherwise `FALSE` is returned.

## Return value

A `BOOLEAN` value that indicates whether the function succeeded. If the function succeeds, the return value is `TRUE`. If the function fails, the return value is `FALSE`. To get extended error information, call the [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

## See also

[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file)