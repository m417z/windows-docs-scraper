# IEditionUpgradeHelper::CanUpgrade

## Description

Checks if the user has sufficient permissions to upgrade the operating system, and prompts the user to run as an administrator if needed.

## Parameters

### `isAllowed` [out]

TRUE if the user has sufficient permissions to upgrade the operating system; otherwise FALSE.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IEditionUpgradeHelper](https://learn.microsoft.com/windows/desktop/api/editionupgradehelper/nn-editionupgradehelper-ieditionupgradehelper)