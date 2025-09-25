# IPropertySheetProvider::FindPropertySheet

## Description

The **IPropertySheetProvider::FindPropertySheet** method determines whether a specific property sheet exists.

## Parameters

### `hItem`

A handle to the selected item in the scope pane.

### `lpComponent` [in]

A pointer to the
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) interface on the selected object. **NULL** if the object selected is a folder (on the scope or result panes), and
**IComponent** of the snap-in if it is a result pane leaf item.

### `lpDataObject` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object.

## Return value

This method can return one of these values.

## Remarks

Items in the scope pane are owned by the console so there is no need to interact with the
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata) interface. The snap-in must implement
[IComponent::CompareObjects](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-compareobjects) or
[IComponentData::CompareObjects](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-compareobjects) to compare the data object with other data objects for existing property sheets.

## See also

[IPropertySheetProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetprovider)