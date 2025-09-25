# SE_OBJECT_TYPE enumeration

## Description

The **SE_OBJECT_TYPE** enumeration contains values that correspond to the types of Windows objects that support security. The functions, such as
[GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo) and
[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo), that set and retrieve the security information of an object, use these values to indicate the type of object.

## Constants

### `SE_UNKNOWN_OBJECT_TYPE`

Unknown object type.

### `SE_FILE_OBJECT`

Indicates a file or directory. The name string that identifies a file or directory object can be in one of the following formats:

* A relative path, such as *FileName.dat* or ..\*FileName*
* An absolute path, such as *FileName.dat*, C:\*DirectoryName*\*FileName.dat*, or G:\*RemoteDirectoryName*\*FileName.dat*.
* A UNC name, such as \\*ComputerName*\*ShareName*\*FileName.dat*.

### `SE_SERVICE`

Indicates a Windows service. A service object can be a local service, such as *ServiceName*, or a remote service, such as \\*ComputerName*\*ServiceName*.

### `SE_PRINTER`

Indicates a printer. A printer object can be a local printer, such as *PrinterName*, or a remote printer, such as \\*ComputerName*\*PrinterName*.

### `SE_REGISTRY_KEY`

Indicates a registry key. A registry key object can be in the local registry, such as **CLASSES_ROOT**\*SomePath* or in a remote registry, such as \\*ComputerName*\**CLASSES_ROOT**\*SomePath*.

The names of registry keys must use the following literal strings to identify the predefined registry keys: "CLASSES_ROOT", "CURRENT_USER", "MACHINE", and "USERS".

### `SE_LMSHARE`

Indicates a network share. A share object can be local, such as *ShareName*, or remote, such as \\*ComputerName*\*ShareName*.

### `SE_KERNEL_OBJECT`

Indicates a local
[kernel object](https://learn.microsoft.com/windows/desktop/SysInfo/kernel-objects).

The
[GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo) and
[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo) functions support all types of kernel objects. The
[GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa) and
[SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa) functions work only with the following kernel objects: semaphore, event, mutex, waitable timer, and file mapping.

### `SE_WINDOW_OBJECT`

Indicates a window station or desktop object on the local computer. You cannot use
[GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa) and
[SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa) with these objects because the names of window stations or desktops are not unique.

### `SE_DS_OBJECT`

Indicates a directory service object or a property set or property of a directory service object.

The name string for a directory service object must be in [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) form, for example:

CN=*SomeObject*,OU=*ou2*,OU=*ou1*,DC=*DomainName*,DC=*CompanyName*,DC=com,O=internet

### `SE_DS_OBJECT_ALL`

Indicates a directory service object and all of its property sets and properties.

### `SE_PROVIDER_DEFINED_OBJECT`

Indicates a provider-defined object.

### `SE_WMIGUID_OBJECT`

Indicates a WMI object.

### `SE_REGISTRY_WOW64_32KEY`

Indicates an object for a registry entry under WOW64.

### `SE_REGISTRY_WOW64_64KEY`

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa)

[GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo)

[SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa)

[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo)