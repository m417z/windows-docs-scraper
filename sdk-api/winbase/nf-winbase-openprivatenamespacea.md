# OpenPrivateNamespaceA function

## Description

Opens a private namespace.

## Parameters

### `lpBoundaryDescriptor` [in]

A descriptor that defines how the namespace is to be isolated. The [CreateBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createboundarydescriptora) function creates a boundary descriptor.

### `lpAliasPrefix` [in]

The prefix for the namespace. To create an object in this namespace, specify the object name as *prefix*\*objectname*.

## Return value

The function returns the handle to the existing namespace.

## Remarks

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later.

## See also

[ClosePrivateNamespace](https://learn.microsoft.com/windows/desktop/api/namespaceapi/nf-namespaceapi-closeprivatenamespace)

[CreateBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createboundarydescriptora)

[CreatePrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprivatenamespacea)

[Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces)