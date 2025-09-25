# IWizardExtension::GetFirstPage

## Description

Gets a handle to the first page of the wizard extension.

## Parameters

### `phpage` [out]

Type: **HPROPSHEETPAGE***

A pointer to a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) handle representing the first page of any wizard extension pages.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Although the wizard extension may host several sequential HTML pages, if it consists of only one page, the handles returned by **IWizardExtension::GetFirstPage** and [IWizardExtension::GetLastPage](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-iwizardextension-getlastpage) are the same.

## See also

[IWizardExtension](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iwizardextension)

[IWizardExtension::GetLastPage](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-iwizardextension-getlastpage)