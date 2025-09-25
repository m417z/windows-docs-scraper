# IUIAutomationElement::GetRuntimeId

## Description

Retrieves the unique identifier assigned to the UI element.

## Parameters

### `runtimeId` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives a pointer to the runtime ID as an array of integers.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The identifier is only guaranteed to be unique to the UI of the desktop on which it was generated. Identifiers can be reused over time.

The format of run-time identifiers might change in the future. The returned identifier should be treated as an opaque value and used only for comparison; for example, to determine whether a Microsoft UI Automation element is in the cache.

## See also

[Automation Element Property IDs](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-automation-element-propids)

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

[CompareRuntimeIds](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-compareruntimeids)

**Conceptual**

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

**Reference**