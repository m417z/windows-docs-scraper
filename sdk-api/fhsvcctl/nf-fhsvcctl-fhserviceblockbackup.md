# FhServiceBlockBackup function

## Description

This function temporarily blocks backups for the current user.

> [!NOTE]
> **FhServiceBlockBackup** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Pipe` [in]

The communication channel handle returned by an earlier [FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe) call.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

This function instructs the File History Service to not perform backups for the current user until the [FhServiceUnblockBackup](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceunblockbackup) function is called or the communication channel with the File History Service is closed by calling [FhServiceClosePipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceclosepipe).

Call this function prior to performing File History configuration reassociation to ensure that File History configuration and data files are not currently in use. (Otherwise, the [IFhReassociation::PerformReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-performreassociation) method may fail.)

## See also

[FhServiceClosePipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceclosepipe)

[FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe)

[FhServiceUnblockBackup](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceunblockbackup)

[IFhReassociation::PerformReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-performreassociation)