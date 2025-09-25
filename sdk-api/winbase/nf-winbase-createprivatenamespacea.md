# CreatePrivateNamespaceA function

## Description

Creates a private namespace.

## Parameters

### `lpPrivateNamespaceAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies the security attributes of the namespace object.

### `lpBoundaryDescriptor` [in]

A descriptor that defines how the namespace is to be isolated. The caller must be within this boundary. The [CreateBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createboundarydescriptora) function creates a boundary descriptor.

### `lpAliasPrefix` [in]

The prefix for the namespace. To create an object in this namespace, specify the object name as *prefix*\*objectname*.

The system supports multiple private namespaces with the same name, as long as they define different boundaries.

## Return value

If the function succeeds, it returns a handle to the new namespace.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Other applications can access the namespace using the [OpenPrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openprivatenamespacea) function.

The application that created the namespace can use the [ClosePrivateNamespace](https://learn.microsoft.com/windows/desktop/api/namespaceapi/nf-namespaceapi-closeprivatenamespace) function to close the handle to the namespace. The handle is also closed when the creating process terminates. After the namespace handle is closed, subsequent calls to [OpenPrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openprivatenamespacea) fail, but all operations on objects in the namespace succeed.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later.

## See also

[ClosePrivateNamespace](https://learn.microsoft.com/windows/desktop/api/namespaceapi/nf-namespaceapi-closeprivatenamespace)

[Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces)

[OpenPrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openprivatenamespacea)