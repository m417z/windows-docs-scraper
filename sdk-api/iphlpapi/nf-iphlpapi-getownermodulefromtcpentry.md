# GetOwnerModuleFromTcpEntry function

## Description

The **GetOwnerModuleFromTcpEntry** function retrieves data about the module that issued the context bind for a specific IPv4 TCP endpoint in a MIB table row.

## Parameters

### `pTcpEntry` [in]

A pointer to a [MIB_TCPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_owner_module) structure that contains the IPv4 TCP endpoint entry used to obtain the owner module.

### `Class` [in]

 A [TCPIP_OWNER_MODULE_INFO_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcpip_owner_module_info_class) enumeration value that indicates the type of data to obtain regarding the owner module. The **TCPIP_OWNER_MODULE_INFO_CLASS** enumeration is defined in the *Iprtrmib.h* header file.

 This parameter must be set to **TCPIP_OWNER_MODULE_INFO_BASIC**.

### `pBuffer` [out]

A pointer a buffer that contains a [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) structure with the owner module data. The type of data returned in this buffer is indicated by the value of the *Class* parameter.

The following structures are used for the data in *Buffer* when *Class* is set to the corresponding value.

| *Class* enumeration value | *Buffer* data format |
| --- | --- |
| TCPIP_OWNER_MODULE_BASIC_INFO | [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) |

### `pdwSize` [in, out]

The estimated size, in bytes, of the structure returned in *Buffer*. If this value is set too small, **ERROR_INSUFFICIENT_BUFFER** is returned by this function, and this field will contain the correct size of the buffer. The size required is the size of the corresponding structure plus an additional number of bytes equal to the length of data pointed to in the structure (for example, the name and path strings).

## Return value

If the function call is successful, the value **NO_ERROR** is returned.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | Insufficient space was allocated for the table. The size of the table is returned in the *pdwSize* parameter, and must be used in a subsequent call to this function in order to successfully retrieve the table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This value is returned if either of the *pTcpEntry* or *pdwSize* parameters are **NULL**. This value is also returned if the *Class* parameter is not equal to **TCPIP_OWNER_MODULE_INFO_BASIC**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to complete the operation. |
| **ERROR_NOT_FOUND** | A element was no found. This value is returned if the **dwOwningPid** member of the [MIB_TCPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_owner_module) structure pointed to by the *pTcpEntry* parameter was zero or could not be found. |
| **ERROR_PARTIAL_COPY** | Only part of a request was completed. |

## Remarks

The *Buffer* parameter contains not only a structure with pointers to specific data, for example, pointers to the zero-terminated strings that contain the name and path of the owner module, but the actual data itself; that is the name and path strings. Therefore, when calculating the buffer size, ensure that you have enough space for both the structure as well as the data the members of the structure point to.

The resolution of TCP table entries to owner modules is a best practice. In a few cases, the owner module name returned in the [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) structure can be a process name, such as "svchost.exe", a service name (such as "RPC"), or a component name, such as "timer.dll".

For computers running on Windows Vista or later, the **pModuleName** and **pModulePath** members of the [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) retrieved by **GetOwnerModuleFromTcpEntry** function may point to an empty string for some TCP connections. Applications that start TCP connections located in the Windows system folder (C:\Windows\System32, by default) are considered protected. If the **GetOwnerModuleFromTcpEntry** function is called by a user that is not a member of the Administrators group, the function call will succeed but the **pModuleName** and **pModulePath** members will point to memory that contains an empty string for the TCP connections started by protected applications.

For computers running on Windows Vista or later, accessing the **pModuleName** and **pModulePath** members of the [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) structure is limited by user account control (UAC). If an application that calls this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will succeed but access to these members returns an empty string unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application on Windows Vista or later lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for access to the protected **pModuleName** and **pModulePath** members to be allowed.

## See also

[MIB_TCPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_owner_module)

[TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info)