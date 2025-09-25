# IWizardSite::GetPreviousPage

## Description

Called when the user navigates backward out of the wizard extension. Gets the handle of the [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) that represents the wizard page that is before the wizard extension page.

## Parameters

### `phpage` [out]

Type: **HPROPSHEETPAGE***

A pointer to a variable handle of type [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) that represents the wizard page that comes immediately before the wizard extension page.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.