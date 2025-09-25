# IVirtualizedItemProvider::Realize

## Description

Makes the virtual item fully accessible as a UI Automation element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When an item is obtained from a virtual list, it is only a placeholder. Use this method to convert it to a full reference to UI Automation element.

## See also

[IVirtualizedItemProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ivirtualizeditemprovider)