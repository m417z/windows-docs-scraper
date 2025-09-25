# QueryProtectedPolicy function

## Description

Queries the value associated with a protected policy.

## Parameters

### `PolicyGuid` [in]

 The globally-unique identifier of the policy to query.

### `PolicyValue` [out]

 Receives the value that the supplied policy is set to.

## Return value

True if the function succeeds; otherwise, false.

## Remarks

Protected policies are process-wide configuration settings that are stored in read-only memory. This is intended to help protect the policy from being corrupted or altered in an unintended way while an application is executing.

To compile an application that calls this function, define _WIN32_WINNT as 0x0603 or later. For more information, see [Using the Windows Headers.](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers)

This function became available in Windows 8.1 and Windows Server 2012 R2 update 3 (the November 2014 update).