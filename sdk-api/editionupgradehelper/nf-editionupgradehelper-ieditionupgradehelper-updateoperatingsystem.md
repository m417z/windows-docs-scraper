# IEditionUpgradeHelper::UpdateOperatingSystem

## Description

Upgrades the installed edition of the operating system to the edition that the user purchased in the Windows Store, or gets a genuine copy of the operating system.

## Parameters

### `contentId` [in]

The content identifier of the edition of the operating system that the user purchased and which the method should install.

If this edition is a higher edition that the currently installed edition of Windows, this method performs an upgrade to that edition, If this edition is the same edition as the currently installed edition, this method installs a genuine copy of that edition.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When this method performs an upgrade from the currently installed edition, the method takes the following steps:

* Upgrades the edition of the operating system to the product that the user purchased from the Windows Store.
* Displays a user interface that informs the user of the progress of the upgrade.
* Restarts the computer when the upgrade is complete.
* Relies on other system components to check the license to when the computer restarts.

When this method installs a genuine copy of the operating system, the method takes the following steps:

* Checks the license that was download from the store before **UpdateOperatingSystem** was called.
* Turns off any user experience that is not genuine for the current edition of Windows.

## See also

[CanUpgrade](https://learn.microsoft.com/windows/desktop/api/editionupgradehelper/nf-editionupgradehelper-ieditionupgradehelper-canupgrade)

[GetGenuineLocalStatus](https://learn.microsoft.com/windows/desktop/api/editionupgradehelper/nf-editionupgradehelper-ieditionupgradehelper-getgenuinelocalstatus)

[GetOsProductContentId](https://learn.microsoft.com/windows/desktop/api/editionupgradehelper/nf-editionupgradehelper-ieditionupgradehelper-getosproductcontentid)

[IEditionUpgradeHelper](https://learn.microsoft.com/windows/desktop/api/editionupgradehelper/nn-editionupgradehelper-ieditionupgradehelper)