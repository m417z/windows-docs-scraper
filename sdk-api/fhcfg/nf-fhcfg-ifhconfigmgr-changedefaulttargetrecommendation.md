# IFhConfigMgr::ChangeDefaultTargetRecommendation

## Description

Causes the currently assigned backup target to be recommended or not recommended to other members of the home group that the computer belongs to.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Recommend` [in]

If set to **TRUE**, the currently assigned backup target is recommended to other members of the home group. If set to **FALSE** and the currently assigned backup target is currently recommended to other members of the home group, this recommendation is withdrawn.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code such as one of the values defined in the FhErrors.h header file.

## Remarks

When a backup target is recommended to other computers in the home group, users on those computers see that storage device in the list of available backup targets in the File History item in Control Panel.

If the backup target is not recommended to other computers in the home group, or if the recommendation is withdrawn, the target does not appear in the list of available backup targets on the other computers.

A backup target cannot be recommended or not recommended on a computer that is joined to a domain or on a computer that is having ARM architecture.

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)