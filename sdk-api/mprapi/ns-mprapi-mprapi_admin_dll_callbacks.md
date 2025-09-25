# MPRAPI_ADMIN_DLL_CALLBACKS structure

## Description

The
**MPRAPI_ADMIN_DLL_CALLBACKS** structure is used by the
[MprAdminInitializeDllEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininitializedllex) function to register the callback function pointers.

## Members

### `revision`

A value that represents the version of this structure.

| Value | Meaning |
| --- | --- |
| **MPRAPI_ADMIN_DLL_VERSION_1** | The [RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex) structure and the callback function pointers that use it as a parameter are not supported by this structure. |
| **MPRAPI_ADMIN_DLL_VERSION_2** | The [RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex) structure and the callback function pointers that use it as a parameter are supported by this structure. |

### `lpfnMprAdminGetIpAddressForUser`

A function pointer to an instance of the [MprAdminGetIpAddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetipaddressforuser) callback. The callback prototype is defined as:

```cpp
typedef DWORD (APIENTRY * PMPRADMINGETIPADDRESSFORUSER)(WCHAR *, WCHAR *, DWORD *, BOOL *);

```

### `lpfnMprAdminReleaseIpAddress`

A function pointer to an instance of the [MprAdminReleaseIpAddress](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipaddress) callback. The callback prototype is defined as:

```cpp
typedef VOID  (APIENTRY * PMPRADMINRELEASEIPADRESS)(WCHAR *, WCHAR *, DWORD *);

```

### `lpfnMprAdminGetIpv6AddressForUser`

A function pointer to an instance of the [MprAdminGetIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetipv6addressforuser) callback. The callback prototype is defined as:

```cpp
typedef DWORD (APIENTRY * PMPRADMINGETIPV6ADDRESSFORUSER)(WCHAR *, WCHAR *, IN6_ADDR *, BOOL *);

```

### `lpfnMprAdminReleaseIpV6AddressForUser`

A function pointer to an instance of the [MprAdminReleaseIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipv6addressforuser) callback. The callback prototype is defined as:

```cpp
typedef VOID  (APIENTRY * PMPRADMINRELEASEIPV6ADDRESSFORUSER)(WCHAR *, WCHAR *, IN6_ADDR *);

```

### `lpfnRasAdminAcceptNewLink`

A function pointer to an instance of the [MprAdminAcceptNewLink](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewlink) callback. The callback prototype is defined as:

```cpp
typedef BOOL  (APIENTRY * PMPRADMINACCEPTNEWLINK)(RAS_PORT_0 *, RAS_PORT_1 *);

```

### `lpfnRasAdminLinkHangupNotification`

A function pointer to an instance of the [MprAdminLinkHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminlinkhangupnotification) callback. The callback prototype is defined as:

```cpp
typedef VOID  (APIENTRY * PMPRADMINLINKHANGUPNOTIFICATION)(RAS_PORT_0 *, RAS_PORT_1 *);

```

### `lpfnRasAdminTerminateDll`

A function pointer to an instance of the [MprAdminTerminateDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminterminatedll) callback. The callback prototype is defined as:

```cpp
typedef DWORD (APIENTRY * PMPRADMINTERMINATEDLL)();

```

### `lpfnRasAdminAcceptNewConnectionEx`

A function pointer to an instance of the [MprAdminAcceptNewConnectionEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnectionex) callback. The callback prototype is defined as:

```cpp
typedef BOOL  (APIENTRY * PMPRADMINACCEPTNEWCONNECTIONEX)(RAS_CONNECTION_EX *);

```

### `lpfnRasAdminAcceptEndpointChangeEx`

### `lpfnRasAdminAcceptReauthenticationEx`

A function pointer to an instance of the [MprAdminAcceptReauthenticationEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptreauthenticationex) callback. The callback prototype is defined as:

```cpp
typedef BOOL  (APIENTRY * PMPRADMINACCEPTREAUTHENTICATIONEX)(RAS_CONNECTION_EX *);

```

### `lpfnRasAdminConnectionHangupNotificationEx`

A function pointer to an instance of the [MprAdminConnectionHangupNotificationEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotificationex) callback. The callback prototype is defined as:

```cpp
typedef VOID  (APIENTRY * PMPRADMINCONNECTIONHANGUPNOTIFICATIONEX)(RAS_CONNECTION_EX *);

```

### `lpfnRASValidatePreAuthenticatedConnectionEx`

## Remarks

The following restrictions apply to the callback functions in the **MPRAPI_ADMIN_DLL_CALLBACKS** structure:

* Both **lpfnMprAdminGetIpv6AddressForUser** and **lpfnMprAdminReleaseIpV6AddressForUser** must be implemented, or neither are implemented.
* Both **lpfnMprAdminGetIpAddressForUser** and **lpfnMprAdminReleaseIpAddress** must be implemented, or neither are implemented.
* Either **lpfnRasAdminLinkHangupNotification** or **lpfnRasAdminAcceptNewLink** must be implemented.
* Either **lpfnRasAdminAcceptNewConnectionEx** or **lpfnRasAdminConnectionHangupNotificationEx** must be implemented.

## See also

[IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85))

[MprAdminAcceptNewConnectionEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnectionex)

[MprAdminAcceptNewLink](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewlink)

[MprAdminAcceptReauthenticationEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptreauthenticationex)

[MprAdminConnectionHangupNotificationEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotificationex)

[MprAdminGetIpAddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetipaddressforuser)

[MprAdminGetIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetipv6addressforuser)

[MprAdminInitializeDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininitializedll)

[MprAdminLinkHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminlinkhangupnotification)

[MprAdminReleaseIpAddress](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipaddress)

[MprAdminReleaseIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipv6addressforuser)

[MprAdminTerminateDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminterminatedll)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex)

[RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0)

[RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)