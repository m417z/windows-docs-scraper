# NPPasswordChangeNotify function

## Description

> [!NOTE]
> This API has been deprecated and will be removed in a future release.

MPR calls this function to notify the credential manager of a password change event. The **NPPasswordChangeNotify** function is implemented by a credential manager DLL.

## Parameters

### `lpAuthentInfoType` [in]

Pointer to a string that identifies the type of structure pointed to by *lpAuthentInfo*.

When Microsoft is the primary authenticator, the following string is specified for interactive and service controller logons.

```cpp
MSV1_0:Interactive
Kerberos:Interactive

```

### `lpAuthentInfo` [in]

Pointer to a structure that contains the new credentials.

When Microsoft is the primary authenticator (that is, when *lpAuthentifoType* is "MSV1_0:Interactive" or "Kerberos:Interactive"), the structure used is
[MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon) or
[KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon).

### `lpPreviousAuthentInfoType` [in]

Pointer to a string that identifies the type of structure pointed to by *lpPreviousAuthentInfo*. If the pointer is **NULL**, there was no previous information. The values that are expected here are the same as those in *lpAuthentInfoType*.

When Microsoft is the primary authenticator, the following string is specified for interactive and service controller logons.

```cpp
MSV1_0:Interactive

```

### `lpPreviousAuthentInfo` [in]

Pointer to a structure that contains the credentials used before the authentication information change. Prior information is provided if the user was forced to change the password (or other authentication information) before logging on. If the user was not forced to change authentication information, this pointer is **NULL**. The values expected here are the same as those in *lpAuthentInfo*.

When Microsoft is the primary authenticator, the structure used is
[MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon) or
[KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon).

### `lpStationName` [in]

Pointer to a string that specifies the name of the station the user has logged on to. The station name may be used to determine whether additional provider-specific information can be obtained.

When Microsoft is the primary authenticator, one of the following strings will be specified.

| Value | Meaning |
| --- | --- |
| **WinSta_0** | Indicates that this is an interactive logon through the window station. In this case, *StationHandle* is an **HWND** to the parent dialog box. |
| **SvcCtl** | Indicates that this is a logon initiated by the service controller. *StationHandle* is not used in this case. |

### `StationHandle` [in]

A 32-bit value whose meaning is dependent upon the name (and consequently, the type) of the station specified in *lpStationName*.

| Value | Meaning |
| --- | --- |
| **WinSta_0** | A handle to the owner dialog box (hwndOwner) currently displayed on the screen. |
| **SvcCtl** | Random data. Do not use. |

### `dwChangeInfo` [in]

If set, specifies a flag that provides change information. This parameter can be one of the flags.

| Value | Meaning |
| --- | --- |
| **WN_VALID_LOGON_ACCOUNT** | This flag indicates that the authentication information changed will affect all future logons. The user belongs to a trusted domain. |
| **WN_NT_PASSWORD_CHANGED** | This flag indicates that the password was changed. <br><br>Some authentication information changes will only affect connections made in untrusted domains. These are the accounts that the user cannot use to log onto this computer anyway. In these cases, *dwChangeInfo* is not set. |

## Return value

If the function succeeds, the function returns WN_SUCCESS.

If the function fails, it returns an error code, which can be one of the following values.

| Return code | Description |
| --- | --- |
| **WN_NOT_SUPPORTED** | [NPPasswordChangeNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-nppasswordchangenotify) is not supported. |
| **WN_NO_NETWORK** | The network is not present. |
| **WN_FUNCTION_BUSY** | The credential manager is still initializing and is not ready to be called. |

## Remarks

The **NPPasswordChangeNotify** function is implemented by credential managers to receive notifications when authentication information changes.

**Windows Server 2003 and Windows XP:** **NPPasswordChangeNotify** is called on a computer a user is logging into if the password has been changed somewhere else. Note that this behavior is not supported beginning with Windows Vista and Windows Server 2008.

## See also

[MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon)

[NPGetCaps](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetcaps)

[NPLogonNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-nplogonnotify)