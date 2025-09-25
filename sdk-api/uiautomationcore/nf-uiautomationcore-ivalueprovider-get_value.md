# IValueProvider::get_Value

## Description

The value of the control.

This property is read-only.

## Parameters

## Remarks

Single-line edit controls support programmatic access to their contents by implementing [IValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ivalueprovider) (in addition to [ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)). However, multi-line edit controls do not implement **IValueProvider**.

To retrieve the textual contents of multi-line edit controls, the controls must implement [ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider). However, **ITextProvider** does not support setting the value of a control.

[IValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ivalueprovider) does not support the retrieval of formatting information or substring values. Implement [ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider) in these scenarios.

## See also

[IValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ivalueprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)