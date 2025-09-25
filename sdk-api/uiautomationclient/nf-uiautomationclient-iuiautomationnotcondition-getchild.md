# IUIAutomationNotCondition::GetChild

## Description

Retrieves the condition of which this condition is the negative.

## Parameters

### `condition` [out, retval]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)****

Receives a pointer to the condition.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The returned condition is the one that was used in creating this condition.

## See also

[CreateNotCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createnotcondition)

[IUIAutomationNotCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationnotcondition)