# WTSConnectSessionW function

## Description

Connects a Remote Desktop Services session to an existing session on the local computer.

## Parameters

### `LogonId` [in]

The logon ID of the session to connect to. The user of that session must have permissions to connect to an existing session. The output of this session will be routed to the session identified by the *TargetLogonId* parameter.

This can be **LOGONID_CURRENT** to use the current session.

### `TargetLogonId` [in]

The logon ID of the session to receive the output of the session represented by the *LogonId* parameter. The output of the session identified by the *LogonId* parameter will be routed to this session.

This can be **LOGONID_CURRENT** to use the current session.

### `pPassword` [in]

A pointer to the password for the user account that is specified in the *LogonId* parameter. The value of *pPassword* can be an empty string if the caller is logged on using the same domain name and user name as the logon ID. The value of *pPassword* cannot be **NULL**.

### `bWait` [in]

Indicates whether the operation is synchronous. Specify **TRUE** to wait for the operation to complete, or **FALSE** to return immediately.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Either the *LogonId* or *TargetLogonId* parameter can be **LOGONID_CURRENT**, but not both.

> [!NOTE]
> The wtsapi32.h header defines WTSConnectSession as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).