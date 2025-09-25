# IUIAutomationPatternInstance::GetProperty

## Description

The client wrapper object implements the **IUIAutomation::get_Current***X* and **IUIAutomationElement::get_Cached***X* methods by calling this function, specifying the property by index.

## Parameters

### `index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the property.

### `cached` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the property should be retrieved from the cache, otherwise **FALSE**.

### `type` [in]

Type: **[UIAutomationType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)**

A value indicating the data type of the property.

### `pPtr` [out, retval]

Type: **void***

Receives the value of the property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationPatternInstance](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationpatterninstance)