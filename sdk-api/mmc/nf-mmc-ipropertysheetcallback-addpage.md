# IPropertySheetCallback::AddPage

## Description

The **IPropertySheetCallback::AddPage** method enables a snap-in to add a page to a property sheet.

## Parameters

### `hPage` [in]

A value that specifies the handle to the page to be added. The hPage parameter is a handle to a
[PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v3) structure created by the Windows API
[CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea).

## Return value

This method can return one of these values.

## Remarks

The snap-in cannot call
AddPage from within a property page handler because the property page is created and runs on a secondary thread. A snap-in cannot call an MMC interface from a different thread than the one in which the snap-in was created. The correct place to call
AddPage is in the snap-in's implementation of the
[IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)) method.

If a snap-in uses the
IPropertySheetProvider interface directly, it can use
AddPage to add the primary pages and then call [IPropertySheetProvider::AddPrimaryPages](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-addprimarypages) (**NULL**, **FALSE**, **NULL**, [**TRUE** or **FALSE**]) so that the provider will add these pages to the property sheet. For more information about how to create your property pages in the snap-in's implementation of
[IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)), see **IPropertySheetProvider::AddPrimaryPages**.

Pages are added to the sheet in the order in which they are presented. The primary snap-in's pages are always added first.

## See also

[IPropertySheetCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetcallback)