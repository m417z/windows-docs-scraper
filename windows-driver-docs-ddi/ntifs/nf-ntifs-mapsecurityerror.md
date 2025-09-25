# MapSecurityError function

## Description

The **MapSecurityError** function maps a security interface SECURITY_STATUS status code to a corresponding NSTATUS status code.

## Parameters

### `SecStatus`

The security interface SECURITY_STATUS status code to be mapped.

## Return value

The NTSTATUS status code corresponding to the input Error status code.

## Remarks

This function maps a security interface status code of type SECURITY_STATUS to a corresponding NSTATUS status code.