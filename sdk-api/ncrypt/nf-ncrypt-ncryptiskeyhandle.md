# NCryptIsKeyHandle function

## Description

The **NCryptIsKeyHandle** function determines if the specified handle is a CNG key handle.

## Parameters

### `hKey` [in]

The handle of the key to test.

## Return value

Returns a nonzero value if the handle is a key handle or zero otherwise.

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.