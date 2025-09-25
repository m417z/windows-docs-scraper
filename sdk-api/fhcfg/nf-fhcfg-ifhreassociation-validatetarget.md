# IFhReassociation::ValidateTarget

## Description

 This method checks whether a certain storage device or network share can be used as a File History default target and, thus, whether reassociation is possible at all or not.

> [!NOTE]
> **IFhReassociation** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `TargetUrl` [in]

Specifies the storage device or network share to be validated.

### `ValidationResult` [out]

On return, contains a value specifying the result of the device validation. See the [FH_DEVICE_VALIDATION_RESULT](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_device_validation_result) enumeration for a detailed description of supported device validation results.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

For local disks, the *TargetUrl* parameter contains the drive letter. This path must end with a trailing backslash (for example, "X:\\").

For network shares, the *TargetUrl* parameter contains the full path of the share. This path must end with a trailing backslash (for example, "\\\\myserver\myshare\\").

## See also

[FH_DEVICE_VALIDATION_RESULT](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_device_validation_result)

[FhReassociation](https://learn.microsoft.com/windows/desktop/DevNotes/fhreassociation)

[IFhReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhreassociation)