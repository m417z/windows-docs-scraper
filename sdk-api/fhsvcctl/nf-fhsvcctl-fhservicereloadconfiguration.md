# FhServiceReloadConfiguration function

## Description

This function causes the File History Service to reload the current user’s File History configuration files.

> [!NOTE]
> **FhServiceReloadConfiguration** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Pipe` [in]

The communication channel handle returned by an earlier [FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe) call.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

This function causes the File History Service to schedule periodic backups for the current user if they have not been scheduled yet and File History is enabled for that user.

It is recommended to call this function every time a policy is changed in File History configuration via the [IFhConfigMgr::SetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setlocalpolicy) method. It should also be called after File History has been enabled or disabled for a user.

## See also

[FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe)

[FhServiceStopBackup](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhservicestopbackup)