# IWizardExtension::GetLastPage

## Description

Gets a handle to the final page of the wizard extension pages.

## Parameters

### `phpage` [out]

Type: **HPROPSHEETPAGE***

A pointer to a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) handle representing the wizard extension's final page.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This value is used to navigate backward into the wizard extension pages when the user clicks the **Back** button.

Although the wizard extension may host several sequential HTML pages, if it consists of only one page the handles returned by [IWizardExtension::GetFirstPage](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-iwizardextension-getfirstpage) and **IWizardExtension::GetLastPage** are the same.

## See also

[IWizardExtension](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iwizardextension)

[IWizardExtension::GetFirstPage](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-iwizardextension-getfirstpage)