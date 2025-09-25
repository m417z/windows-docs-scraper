# IUIAutomation::CreateAndConditionFromNativeArray

## Description

Creates a condition that selects elements from a native array, based on multiple conditions that must all be true.

## Parameters

### `conditions` [in]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)****

A pointer to an array of conditions to be combined.

### `conditionCount` [in]

Type: **int**

The number of elements in the *conditions* array.

### `newCondition` [out, retval]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)****

Receives a pointer to the combined condition.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on each pointer in the *conditions* array. This means you can call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on those pointers after the call to **CreateAndConditionFromNativeArray** returns without invalidating the pointer returned from **CreateAndConditionFromNativeArray**. When you call **Release** on the pointer returned from **CreateAndConditionFromNativeArray**, UI Automation calls **Release** on each pointer in the *conditions* array.

## See also

[CreateAndCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createandcondition)

[CreateAndConditionFromArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createandconditionfromarray)

[FindAll](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findall)

[FindAllBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findallbuildcache)

[FindFirst](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirst)

[FindFirstBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirstbuildcache)

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)

**Reference**