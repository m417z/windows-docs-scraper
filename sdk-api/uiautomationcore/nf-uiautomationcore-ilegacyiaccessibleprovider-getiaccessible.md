# ILegacyIAccessibleProvider::GetIAccessible

## Description

Retrieves an accessible object that corresponds to a UI Automation element that supports the [LegacyIAccessible](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementinglegacyiaccessible) control pattern.

## Parameters

### `ppAccessible` [out]

Type: **[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)****

Receives a pointer to the accessible object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ILegacyIAccessibleProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ilegacyiaccessibleprovider)