# ClosePrivateNamespace function

## Description

Closes an open namespace handle.

## Parameters

### `Handle` [in]

The namespace handle. This handle is created by [CreatePrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprivatenamespacea) or [OpenPrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openprivatenamespacea).

### `Flags` [in]

If this parameter is **PRIVATE_NAMESPACE_FLAG_DESTROY** (0x00000001), the namespace is destroyed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later.

## See also

[CreatePrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprivatenamespacea)

[Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces)

[OpenPrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openprivatenamespacea)