# IFhConfigMgr::ValidateTarget

## Description

 Checks whether a certain storage device or network share can be used as a File History backup target.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `TargetUrl` [in]

The storage device or network share to be validated.

### `ValidationResult` [out]

Receives the result of the device validation. See the [FH_DEVICE_VALIDATION_RESULT](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_device_validation_result) enumeration for the list of possible device validation result values.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

For local disks, the *TargetUrl* parameter contains the drive letter. This path must end with a trailing backslash (for example, "X:\\").

For network shares, the *TargetUrl* parameter contains the full path of the share. This path must end with a trailing backslash (for example, "\\\\myserver\myshare\\").

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::GetDefaultTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getdefaulttarget)