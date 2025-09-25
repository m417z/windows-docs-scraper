# IValueProvider::SetValue

## Description

Sets the value of control.

## Parameters

### `val` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value to set. The provider is responsible for converting the value to the appropriate data type.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Single-line edit controls support programmatic access to their contents by implementing [IValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ivalueprovider).
However, multi-line edit controls do not implement **IValueProvider**;
instead they provide access to their content by implementing [ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider).

Controls such as ListItem and TreeItem must implement [IValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ivalueprovider)
if the value of any of the items is editable, regardless of the current edit
mode of the control. The parent control must also implement **IValueProvider**
if the child items are editable.

## See also

[IValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ivalueprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)