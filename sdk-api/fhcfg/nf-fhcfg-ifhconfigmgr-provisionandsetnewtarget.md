# IFhConfigMgr::ProvisionAndSetNewTarget

## Description

Provisions a certain storage device or network share as a File History backup target and assigns it as the default backup target for the current user.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `TargetUrl` [in]

Specifies the storage device or network share to be provisioned and assigned as the default.

### `TargetName` [in]

Specifies a user-friendly name for the specified backup target.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code such as one of the values defined in the FhErrors.h header file.

## Remarks

For local disks, the *TargetUrl* parameter contains the drive letter. This path must end with a trailing backslash (for example, "X:\\").

For network shares, the *TargetUrl* parameter contains the full path of the share. This path must end with a trailing backslash (for example, "\\\\myserver\myshare\\").

It is highly recommended that the storage device or network share specified by the *TargetUrl* parameter be validated first using the [IFhConfigMgr::ValidateTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-validatetarget) method. If **ValidateTarget** returns a validation result other than **FH_VALID_TARGET**, assigning this storage device or network share as the default backup target may have unpredictable consequences.

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::ValidateTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-validatetarget)