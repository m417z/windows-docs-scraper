# SetProtectedPolicy function

## Description

Sets a protected policy. This function is for use primarily by Windows, and not designed for external use.

## Parameters

### `PolicyGuid` [in]

 The globally-unique identifier of the policy to set.

### `PolicyValue` [in]

 The value to set the policy to.

### `OldPolicyValue` [out]

 Optionally receives the original value that was associated with the supplied policy.

## Return value

 True if the function succeeds; otherwise, false. To retrieve error values for this function, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Protected policies are process-wide configuration settings that are stored in read-only memory. This is intended to help protect the policy from being corrupted or altered in an unintended way while an application is executing. Protected policies are primarily a construct internal to Windows.

To compile an application that calls this function, define _WIN32_WINNT as 0x0603 or later. For more information, see [Using the Windows Headers.](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers)

This function became available in update 3 (the November 2014 update) for Windows 8.1 and Windows Server 2012 R2.