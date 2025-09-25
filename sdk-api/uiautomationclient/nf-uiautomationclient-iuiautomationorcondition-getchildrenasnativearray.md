# IUIAutomationOrCondition::GetChildrenAsNativeArray

## Description

Retrieves the conditions that make up this "or" condition, as an ordinary array.

## Parameters

### `childArray` [out]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)*****

Receives a pointer to an array of [IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition) interface pointers.

### `childArrayCount` [out]

Type: **int***

Receives the number of elements in the array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationOrCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationorcondition)

[IUIAutomationOrCondition::GetChildren](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationorcondition-getchildren)