# IEditionUpgradeHelper::GetOsProductContentId

## Description

Retrieves the content identifier that corresponds to the current installation of the operating system. The content identifier is used to look up the operating system product in the store catalog.

## Parameters

### `contentId` [out]

The content identifier that corresponds to the current installation of the operating system.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IEditionUpgradeHelper](https://learn.microsoft.com/windows/desktop/api/editionupgradehelper/nn-editionupgradehelper-ieditionupgradehelper)

[UpdateOperatingSystem](https://learn.microsoft.com/windows/desktop/api/editionupgradehelper/nf-editionupgradehelper-ieditionupgradehelper-updateoperatingsystem)