# FhServiceStartBackup function

## Description

This function starts an immediate backup for the current user.

> [!NOTE]
> **FhServiceStartBackup** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Pipe` [in]

The communication channel handle returned by an earlier [FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe) call.

### `LowPriorityIo` [in]

If **TRUE**, the File History Service is instructed to use low priority I/O for the immediate backup scheduled by this function. Low-priority I/O reduces impact on foreground user activities. It is recommended to set this parameter to **TRUE.**

If **FALSE**, the File History Service is instructed to use normal priority I/O for the immediate backup scheduled by this function. This results in faster backups but negatively affects the responsiveness and performance of user applications.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

This function does not wait until the immediate backup completes. If an error or warning condition is encountered during backup, it is communicated to the user via an Action Center notification and programmatically retrievable via the [IFhConfigMgr::QueryProtectionStatus](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-queryprotectionstatus) method.

A backup cycle initiated by calling this function can be stopped using the [FhServiceStopBackup](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhservicestopbackup) function.

## See also

[FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe)

[FhServiceStopBackup](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhservicestopbackup)

[IFhConfigMgr::QueryProtectionStatus](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-queryprotectionstatus)