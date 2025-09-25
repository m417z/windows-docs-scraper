# GetOwnerModuleFromUdp6Entry function

## Description

The **GetOwnerModuleFromUdp6Entry** function retrieves data about the module that issued the context bind for a specific IPv6 UDP endpoint in a MIB table row.

## Parameters

### `pUdpEntry` [in]

A pointer to a [MIB_UDP6ROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row_owner_module) structure that contains the IPv6 UDP endpoint entry used to obtain the owner module.

### `Class` [in]

[TCPIP_OWNER_MODULE_INFO_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcpip_owner_module_info_class) enumeration value that indicates the type of data to obtain regarding the owner module.

### `pBuffer` [out]

The buffer that contains a [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) structure with the owner module data. The type of data returned in this buffer is indicated by the value of the *Class* parameter.

The following structures are used for the data in *Buffer* when *Class* is set to the corresponding value.

| *Class* enumeration value | *Buffer* data format |
| --- | --- |
| TCPIP_OWNER_MODULE_BASIC_INFO | [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) |

### `pdwSize` [in, out]

The estimated size, in bytes, of the structure returned in *Buffer*. If this value is set too small, **ERROR_INSUFFICIENT_BUFFER** is returned by this function, and this field will contain the correct size of the structure.

## Return value

If the call is successful, the value **NO_ERROR** is returned. Otherwise, the following error is returned.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | An insufficient amount of space was allocated for the table. The size of the table is returned in the *pdwSize* parameter, and must be used in a subsequent call to this function in order to successfully retrieve the table. |

## Remarks

The *Buffer* parameter contains not only a structure with pointers to specific data, for example, pointers to the zero-terminated strings that contain the name and path of the owner module, but the actual data itself; that is the name and path strings. Therefore, when calculating the buffer size, ensure that you have enough space for both the structure as well as the data the members of the structure point to.

The resolution of UDP table entries to owner modules is a best practice. In a few cases, the owner module name returned in the [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) structure can be a process name, such as "svchost.exe", a service name, such as "RPC", or a component name, such as "timer.dll".

For computers running on Windows Vista or later, accessing the **pModuleName** and **pModulePath** members of the [TCPIP_OWNER_MODULE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-tcpip_owner_module_basic_info) structure is limited by user account control (UAC). If an application that calls this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will succeed but access to these members returns an empty string unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application on Windows Vista or later lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for access to the protected **pModuleName** and **pModulePath** members to be allowed.