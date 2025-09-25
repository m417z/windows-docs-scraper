# IPropertySheetProvider::Show

## Description

If the type that has been set in [IPropertySheetProvider::CreatePropertySheet](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-createpropertysheet) is a property sheet, **IPropertySheetProvider::Show** displays a property sheet frame that is parented to a hidden window. If the type that has been set in **IPropertySheetProvider::CreatePropertySheet** is a wizard, **IPropertySheetProvider::Show** displays a property sheet frame parented to the handle that is passed to this method.

## Parameters

### `window` [in]

A value that specifies the handle to the parent window.

### `page` [in]

A value that specifies which page on the property sheet is shown. It is zero-indexed.

## Return value

This method can return one of these values.

## Remarks

**IPropertySheetProvider::Show(
–1, 0)** returns **E_FAIL**. This return code can be ignored in this case.

In situations in which the snap-in creates a property sheet in a call to [IPropertySheetProvider::CreatePropertySheet](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-createpropertysheet), optionally calls [IPropertySheetProvider::AddPrimaryPages](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-addprimarypages) and [IPropertySheetProvider::AddExtensionPages](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-addextensionpages), and then decides not to show the property sheet, it should call **IPropertySheetProvider::Show(
–1, 0)** to delete the property sheet and free its resources. In this case, the snap-in must delete the property page handles that it has created. This can be done before or after the snap-in calls **IPropertySheetProvider::Show(
–1, 0)**, because MMC does not use the property page handles.

**IPropertySheetProvider::Show(
–1, 0)** only deletes the current property sheet, that is, one that has been created, but is not yet shown. After a property sheet is shown, the snap-in cannot programmatically close it. Only the user can close a property sheet that is shown. In this case, MMC automatically deletes all associated property pages ([PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v3) structures) provided by the snap-in.

## See also

[IPropertySheetProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetprovider)