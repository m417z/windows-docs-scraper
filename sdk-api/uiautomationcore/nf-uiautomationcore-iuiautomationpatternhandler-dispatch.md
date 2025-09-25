# IUIAutomationPatternHandler::Dispatch

## Description

Dispatches a method or property getter to a custom *control pattern* provider.

## Parameters

### `pTarget` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the object that implements the control pattern provider.

### `index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the method or property getter.

### `pParams` [in]

Type: **[UIAutomationParameter](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationparameter)***

A pointer to an array of structures that contain information about the parameters to be passed.

### `cParams` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of parameters in *pParams*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationPatternHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationpatternhandler)