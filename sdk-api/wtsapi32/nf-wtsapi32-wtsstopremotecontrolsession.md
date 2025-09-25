# WTSStopRemoteControlSession function

## Description

Stops a remote control session.

## Parameters

### `LogonId` [in]

The logon ID of the session that you want to stop the remote control of.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).