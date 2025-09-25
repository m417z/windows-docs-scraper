# WTSSetUserConfigA function

## Description

Modifies configuration information for the specified user on the specified domain controller or
Remote Desktop Session Host (RD Session Host) server.

## Parameters

### `pServerName` [in]

Pointer to a null-terminated string containing the name of a domain controller or
RD Session Host server. Specify **WTS_CURRENT_SERVER_NAME** to indicate the
RD Session Host server on which your application is running.

### `pUserName` [in]

Pointer to a null-terminated string containing the name of the user whose configuration is being set.

### `WTSConfigClass` [in]

Specifies the type of information to set for the user. This parameter can be one of the values from the
[WTS_CONFIG_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_config_class) enumeration type. The
documentation for **WTS_CONFIG_CLASS** describes
the format of the data specified in *ppBuffer* for each of the information types.

### `pBuffer` [in]

Pointer to the data used to modify the specified user's configuration.

### `DataLength` [in]

Size, in **TCHARs**, of the *pBuffer* buffer.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga) and
**WTSSetUserConfig** functions are passed a server
name instead of a handle because user account information often resides on a domain controller. To set user
configuration information, use the primary domain controller. You can call the
[NetGetDCName](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgetdcname) function to get the name of the primary
domain controller. To query user configuration information, you can use the
[NetGetAnyDCName](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgetanydcname) function to get the name of a
primary or backup domain controller.

Any domain controller can set or query user configuration information. Use the
[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function to retrieve the name of a domain
controller.

If the value of the *WTSConfigClass* parameter corresponds to an integer value in the
[WTS_CONFIG_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_config_class) enumeration, define the value
to be set as a **DWORD**. Then cast the value to an **LPWSTR**
in the call to **WTSSetUserConfig**, as in the
following example:

```cpp
WTSSetUserConfig( strServer.GetBuffer(0),
                  m_strName.GetBuffer(0),
                  WTSUserConfigfAllowLogonTerminalServer,
                  (LPWSTR) &dwEnable,
                  sizeof(DWORD));
```

> [!NOTE]
> The wtsapi32.h header defines WTSSetUserConfig as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga)

[WTS_CONFIG_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_config_class)