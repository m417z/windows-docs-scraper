# IPropertySheetProvider::CreatePropertySheet

## Description

The **IPropertySheetProvider::CreatePropertySheet** method creates a property sheet frame.

## Parameters

### `title` [in]

A pointer to a null-terminated string that contains the title of the property page. This parameter cannot be **NULL**.

### `type` [in]

**TRUE** creates a property sheet and **FALSE** creates a wizard.

### `cookie` [in]

Cookie value of the currently selected item. This can be **NULL** when
CreatePropertySheet is called by an extension snap-in.

### `pIDataObjectm` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object for the cookie. If the value of this parameter is **NULL**, MMC will not call any of the
IExtendPropertySheet2 methods implemented by extension snap-ins.

### `dwOptions` [in]

A value that specifies the flags that can be set by the method call. The parameter can be a combination of the following values:

#### MMC_PSO_NOAPPLYNOW

Remove Apply Now button.

#### MMC_PSO_HASHELP

Add a
**Help** button.

#### MMC_PSO_NO_PROPTITLE

Ignored for wizards. For property sheets, if this option is specified, then the words "Properties for" will not be inserted at the beginning of the property sheet title bar.

#### MMC_PSO_NEWWIZARDTYPE

Use Wizard 97 style.

For example, to create a property sheet that has a
**Help** button and that does not have an Apply Now button, the dwOptions parameter should be `MMC_PSO_NOAPPLYNOW | MMC_PSO_HASHELP`.

## Return value

This method can return one of these values.

## Remarks

This method creates an object that collects all information required to create a property sheet. If the
CreatePropertySheet call is successful, but subsequent errors occur, you must call
[IPropertySheetProvider::Show](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-show)(
–1, 0) to free objects. The return code can be ignored in this case.

In situations in which the snap-in creates a property sheet in a call to **IPropertySheetProvider::CreatePropertySheet** and then optionally calls [IPropertySheetProvider::AddPrimaryPages](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-addprimarypages) and [IPropertySheetProvider::AddExtensionPages](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-addextensionpages), and then decides not to show the property sheet, it should call [IPropertySheetProvider::Show](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-show)(
–1, 0) to delete the property sheet and free its resources. In this case, the snap-in must delete the property page handles it has created. This can be done before or after the snap-in calls **IPropertySheetProvider::Show**(
–1, 0), because MMC does not use the property page handles.

For a snap-in that targets MMC 1.1, the snap-in must keep an extra reference on the IDataObject interface that it passes to MMC in the **IPropertySheetProvider::CreatePropertySheet** call. This reference must be kept from before the **IPropertySheetProvider::CreatePropertySheet** call until after the property sheet is possibly closed with a call to [IPropertySheetProvider::Show](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-show)(
–1, 0).

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IPropertySheetProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetprovider)

[IPropertySheetProvider::Show](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-show)