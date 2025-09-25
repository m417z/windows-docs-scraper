# IExtendPropertySheet::CreatePropertyPages

## Description

Adds pages to a property sheet.

## Parameters

### `lpProvider` [in]

A pointer to the
[IPropertySheetCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetcallback) interface.

### `handle` [in]

A value that specifies the handle used to route the
[MMCN_PROPERTY_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-property-change) notification message to the appropriate
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) or
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata) interface.

For snap-ins that use the
[IPropertySheetProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetprovider) interface directly, MMC creates the handle when the snap-in calls
[IPropertySheetProvider::AddPrimaryPages](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-addprimarypages) and specifies its bCreateHandle to be **TRUE**.

### `lpIDataObject` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the object that contains context information about the scope or result item.

## Return value

This method can return one of these values.

## Remarks

The IPropertySheetCallback interface is passed to the snap-in during a call to this method. The lifetime of this interface is under the control of MMC. As such, the pointer lpIDataObject is valid only during the lifetime of the immediate call to this method. Caching the lpIDataObject pointer value outside of the callback is not recommended.

The handle specified by the handle parameter must be saved in the property page object to notify the parent of property changes using the API function
[MMCPropertyChangeNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertychangenotify).

If the snap-in returns a success code (S_OK, S_FALSE) from
CreatePropertyPages, then the snap-in must call
MMCFreeNotifyHandle. If the snap-in returns an error code, then MMC immediately frees the handle. For more information about when
MMCFreeNotifyHandle should be called, see
[MMCFreeNotifyHandle](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcfreenotifyhandle).

## See also

[Adding Property Pages and Wizard Pages](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-property-pages-and-wizard-pages)

[IExtendPropertySheet](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendpropertysheet)

[IPropertySheetCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetcallback)

[MMCFreeNotifyHandle](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcfreenotifyhandle)