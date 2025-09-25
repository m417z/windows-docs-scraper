# IExtendPropertySheet::QueryPagesFor

## Description

Determines whether the object requires pages.

## Parameters

### `lpDataObject` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the object that contains context information about the scope or result item.

## Return value

This method can return one of these values.

## Remarks

The console calls this method to determine whether the
**Properties** menu item should be added to the context menu.

## See also

[Adding Property Pages and Wizard Pages](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-property-pages-and-wizard-pages)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IExtendPropertySheet](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendpropertysheet)

[IPropertySheetCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetcallback)