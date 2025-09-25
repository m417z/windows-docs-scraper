# IWizardSite::GetNextPage

## Description

Called when the user navigates forward past the wizard extension pages. Gets the handle of the [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) that represents the wizard page immediately following the wizard extension page.

## Parameters

### `phpage` [out]

Type: **HPROPSHEETPAGE***

A pointer to a handle variable of type [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) for the wizard page following the extension page.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.