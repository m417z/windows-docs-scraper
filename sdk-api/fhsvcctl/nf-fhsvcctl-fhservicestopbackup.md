# FhServiceStopBackup function

## Description

This function stops an ongoing backup cycle for the current user.

> [!NOTE]
> **FhServiceStopBackup** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Pipe` [in]

The communication channel handle returned by an earlier [FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe) call.

### `StopTracking` [in]

If **TRUE**, this function both stops the ongoing backup cycle (if any) and prevents periodic backup cycles for the current user in the future.

If **FALSE**, this function only stops the ongoing backup cycle.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## See also

[FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe)