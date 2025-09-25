# IUIAutomation::CreateOrConditionFromArray

## Description

Creates a combination of two or more conditions where a match exists if any of the conditions is true.

## Parameters

### `conditions` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)***

A pointer to the conditions.

### `newCondition` [out, retval]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)****

Receives a pointer to the combined condition.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on each pointer in the *conditions* array. This means you can call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on those pointers after the call to **CreateOrConditionFromArray** returns without invalidating the pointer returned from **CreateOrConditionFromArray**. When you call **Release** on the pointer returned from **CreateOrConditionFromArray**, UI Automation calls **Release** on each pointer in the *conditions* array.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[CreateOrCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createorcondition)

[CreateOrConditionFromNativeArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createorconditionfromnativearray)

[FindAll](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findall)

[FindAllBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findallbuildcache)

[FindFirst](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirst)

[FindFirstBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirstbuildcache)

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)

**Reference**