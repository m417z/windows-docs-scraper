# MBN_CONTEXT structure

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_CONTEXT** structure stores information about the connection context.

## Members

### `contextID`

Contains the unique identifier for this context. This represents the context index in the device or SIM memory. If it is set to **MBN_CONTEXT_ID_APPEND**, then the device will find the appropriate index to store the context.

### `contextType`

An [MBN_CONTEXT_TYPE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_context_type) value that specifies the context type. An application can use this member to modify the context stored at a particular index using the [SetProvisionedContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectioncontext-setprovisionedcontext) method of [IMbnConnectionContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontext).

### `accessString`

Contains connection-specific access information. In GSM networks, this would be an access point name (APN) such as "data.thephone-company.com". In CDMA networks, this might be a special dial code such as "#777" or a NAI (Network Access Identifier) such as "somebody@thephone-company.com".

This string must not exceed **MBN_ACCESSSTRING_LEN** characters. For the definition of **MBN_ACCESSTRING_LEN**, see [MBN_CONTEXT_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_context_constants). This string can be empty. The calling application must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `userName`

Contains the user name that is used for authentication.

The string must not exceed **MBN_USERNAME_LEN** characters. The calling application must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring). For the definition of **MBN_USERNAME_LEN**, see [MBN_CONTEXT_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_context_constants). The calling application must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `password`

Contains the password that is used for authentication.

The string must not exceed **MBN_PASSWORD_LEN** characters. This string can be empty. For the definition of **MBN_PASSWORD_LEN**, see [MBN_CONTEXT_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_context_constants). The calling application must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `compression`

An [MBN_COMPRESSION](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_compression) value that specifies whether compression is used in the data link for header and data.

This member is applicable only for GSM devices.

### `authType`

An [MBN_AUTH_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_auth_protocol) value that indicates the type of compression used for PDP (Packet Data Protocol) activation.

This member is applicable only for GSM devices. For CDMA devices, it is set to **MBN_AUTH_PROTOCOL_NONE**.