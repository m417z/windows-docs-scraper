# IUIAutomationPatternInstance::CallMethod

## Description

Client wrapper implements methods by calling this CallMethod function, specifying the parameters as an array of pointers.

## Parameters

### `index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the method.

### `pParams` [in]

Type: **[UIAutomationParameter](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationparameter)***

 A pointer to an array of structures describing the parameters.

### `cParams` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of parameters in *pParams*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationPatternInstance](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationpatterninstance)