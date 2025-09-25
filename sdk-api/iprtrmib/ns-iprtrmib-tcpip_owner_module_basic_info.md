# TCPIP_OWNER_MODULE_BASIC_INFO structure

## Description

The **TCPIP_OWNER_MODULE_BASIC_INFO** structure contains pointers to the module name and module path values associated with a TCP connection. The **TCPIP_OWNER_MODULE_BASIC_INFO** structure is returned by the [GetOwnerModuleFromTcpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromtcpentry) and [GetOwnerModuleFromTcp6Entry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromtcp6entry) functions.

## Members

### `pModuleName`

A pointer to the name of the module. This field should be a **NULL** pointer when passed to [GetOwnerModuleFromTcpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromtcpentry) or [GetOwnerModuleFromTcp6Entry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromtcp6entry) function.

### `pModulePath`

A pointer to the full path of the module, including the module name. This field should be a **NULL** pointer when passed to [GetOwnerModuleFromTcpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromtcpentry) or [GetOwnerModuleFromTcp6Entry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromtcp6entry) function.

## Remarks

If the module owner is the system kernel, the **lpModuleName** and **lpModulePath** members point to a wide character string that contains "System".

On Windows Vista and later as well as on the Microsoft Windows Software Development Kit (SDK), the organization of header files has changed and the **TCPIP_OWNER_MODULE_BASIC_INFO** structure is defined in the *Iprtrmib.h* header file.