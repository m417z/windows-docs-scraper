# IUIAutomation::CreateAndCondition

## Description

Creates a condition that selects elements that match both of two conditions.

## Parameters

### `condition1` [in]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)***

A pointer to the first condition to match.

### `condition2` [in]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)***

A pointer to the second condition to match.

### `newCondition` [out, retval]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)****

Receives a pointer to the combined condition.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A condition that combines more than two simple conditions can be created by using [IUIAutomation::CreateAndConditionFromArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createandconditionfromarray) or [IUIAutomation::CreateAndConditionFromNativeArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createandconditionfromnativearray).

The **CreateAndCondition** method calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the *condition1* and *condition2* pointers. This means you can call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on those two pointers after the call to **CreateAndCondition** returns without invalidating the pointer returned from **CreateAndCondition**. When you call **Release** on the pointer returned from **CreateAndCondition**, UI Automation calls **Release** on the *condition1* and *condition2* pointers.

## See also

[CreateAndConditionFromArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createandconditionfromarray)

[FindAll](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findall)

[FindAllBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findallbuildcache)

[FindFirst](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirst)

[FindFirstBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirstbuildcache)

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)

**Reference**