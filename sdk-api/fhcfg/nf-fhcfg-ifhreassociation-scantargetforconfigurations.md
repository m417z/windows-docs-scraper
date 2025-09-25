# IFhReassociation::ScanTargetForConfigurations

## Description

Scans the namespace on a specified storage device or network share for File History configurations that can be reassociated with and continued to be used on the current computer.

> [!NOTE]
> **IFhReassociation** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `TargetUrl` [in]

Specifies the storage device or network share to be scanned.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

If no File History configurations were found on the specified storage device or network share, the `HRESULT_FROM_WIN32(ERROR_NOT_FOUND)` error code is returned.

## Remarks

For local disks, the *TargetUrl* parameter contains the drive letter. This path must end with a trailing backslash (for example, "X:\\").

For network shares, the *TargetUrl* parameter contains the full path of the share. This path must end with a trailing backslash (for example, "\\\\myserver\myshare\\").

## See also

[FhReassociation](https://learn.microsoft.com/windows/desktop/DevNotes/fhreassociation)

[IFhReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhreassociation)