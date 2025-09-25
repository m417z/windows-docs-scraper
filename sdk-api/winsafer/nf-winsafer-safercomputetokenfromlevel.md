# SaferComputeTokenFromLevel function

## Description

The **SaferComputeTokenFromLevel** function restricts a token using restrictions specified by a SAFER_LEVEL_HANDLE.

## Parameters

### `LevelHandle` [in]

**SAFER_LEVEL_HANDLE** that contains the restrictions to place on the input token. Do not pass handles with a LevelId of **SAFER_LEVELID_FULLYTRUSTED** or **SAFER_LEVELID_DISALLOWED** to this function. This is because **SAFER_LEVELID_FULLYTRUSTED** is unrestricted and **SAFER_LEVELID_DISALLOWED** does not contain a token.

### `InAccessToken` [in, optional]

Token to be restricted. If this parameter is **NULL**, the token of the current thread will be used. If the current thread does not contain a token, the token of the current process is used.

### `OutAccessToken` [out]

The resulting restricted token.

### `dwFlags` [in]

Specifies the behavior of the method. The value can be **NULL** or one or more of the following values combined by using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **SAFER_TOKEN_NULL_IF_EQUAL**<br><br>1 (0x1) | If the *OutAccessToken* parameter is not more restrictive than the *InAccessToken* parameter, the *OutAccessToken* parameter returns **NULL**. |
| **SAFER_TOKEN_COMPARE_ONLY**<br><br>2 (0x2) | The token specified by the *InAccessToken* parameter is compared with the token that would be created if the restrictions specified by the *LevelHandle* parameter were applied. The restricted token is not actually created.<br><br>On output, the value of the *lpReserved* parameter specifies the result of the comparison. |
| **SAFER_TOKEN_MAKE_INERT**<br><br>4 (0x4) | If this flag is set, the system does not check [AppLocker](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd723678(v=ws.10)) rules or apply [Software Restriction Policies](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc779607(v=ws.10)). For [AppLocker](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd723678(v=ws.10)), this flag disables checks for all four rule collections: Executable, Windows Installer, Script, and DLL. <br><br>Set this flag when creating a setup program that must run extracted DLLs during installation.<br><br>A token can be queried for existence of this flag by using [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** AppLocker is not supported. |
| **SAFER_TOKEN_WANT_FLAGS**<br><br>8 (0x8) | On output, the value of the *lpReserved* parameter specifies the set of flags used to create the restricted token. |

### `lpReserved` [in, out, optional]

If the **SAFER_TOKEN_COMPARE_ONLY** flag is set, this parameter, on output, specifies the result of the token comparison. The output value is an **LPDWORD**. A value of –1 indicates that the resulting token would be less privileged than the token specified by the *InAccessToken* parameter.

If the **SAFER_TOKEN_WANT_FLAGS** flag is set, and the **SAFER_TOKEN_COMPARE_ONLY** flag is not set, this parameter is an **LPDWORD** value that specifies the flags used to create the restricted token.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**. For extended information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).