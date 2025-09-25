# CreateBoundaryDescriptorA function

## Description

Creates a boundary descriptor.

## Parameters

### `Name` [in]

The name of the boundary descriptor.

### `Flags` [in]

A combination of the following flags that are combined by using a bitwise **OR** operation.

| Flag | Description |
| --------------------------------------------------------------- | ----------- |
| **CREATE_BOUNDARY_DESCRIPTOR_ADD_APPCONTAINER_SID** (0x01)<br>**Note:** This value is not supported prior to Windows 8. | Required for creating a boundary descriptor in an appcontainer process, regardless of producer or consumer. |

## Return value

If the function succeeds, the return value is a handle to the boundary descriptor.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A new boundary descriptor must have at least one security identifier (SID). To add a SID to a boundary descriptor, use the [AddSIDToBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/namespaceapi/nf-namespaceapi-addsidtoboundarydescriptor) function.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later.

## See also

[AddSIDToBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/namespaceapi/nf-namespaceapi-addsidtoboundarydescriptor)

[CreatePrivateNamespace](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprivatenamespacea)

[DeleteBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/namespaceapi/nf-namespaceapi-deleteboundarydescriptor)

[Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces)