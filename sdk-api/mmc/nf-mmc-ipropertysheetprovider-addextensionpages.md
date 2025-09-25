# IPropertySheetProvider::AddExtensionPages

## Description

The **IPropertySheetProvider::AddExtensionPages** method collects the pages from the extension snap-ins.

## Return value

This method can return one of these values.

## Remarks

Snap-ins that use the
[IPropertySheetProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetprovider) interface directly must add at least one page before extensions can add pages. They must also call the **IPropertySheetProvider::AddExtensionPages** method to allow extensions to add their own property pages.

## See also

[IPropertySheetProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetprovider)