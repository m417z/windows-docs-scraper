# IUIAutomationAndCondition::GetChildren

## Description

Retrieves the conditions that make up this "and" condition.

## Parameters

### `childArray` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/dotnet/api/microsoft.visualstudio.ole.interop.safearray)****

Receives a pointer to the child conditions.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[GetChildrenAsNativeArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationandcondition-getchildrenasnativearray)

[IUIAutomationAndCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationandcondition)

**Reference**