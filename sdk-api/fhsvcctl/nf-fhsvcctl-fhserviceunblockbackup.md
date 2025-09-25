# FhServiceUnblockBackup function

## Description

This function unblocks backups blocked via [FhServiceBlockBackup](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceblockbackup).

> [!NOTE]
> **FhServiceUnblockBackup** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Pipe` [in]

The communication channel handle returned by an earlier [FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe) call.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

This function removes the effects of a prior [FhServiceBlockBackup](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceblockbackup) call issued via a given communication channel with the File History Service.

## See also

[FhServiceBlockBackup](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceblockbackup)

[FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe)