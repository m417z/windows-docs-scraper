# ISelectionItemProvider::Select

## Description

Deselects any selected items and then selects the current element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the current element isn’t selected, this method deselects any selected items and then selects the current element. If the current element is already selected, this method does nothing.

## See also

[ISelectionItemProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iselectionitemprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)