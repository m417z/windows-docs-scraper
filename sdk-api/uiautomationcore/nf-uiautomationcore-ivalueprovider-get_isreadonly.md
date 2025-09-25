# IValueProvider::get_IsReadOnly

## Description

Indicates whether the value of a control is read-only.

This property is read-only.

## Parameters

## Remarks

A control should have its IsEnabled property ([UIA_IsEnabledPropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-automation-element-propids)) set to **TRUE** and its **IValueProvider::IsReadOnly**
property set to **FALSE** before allowing a call to [IValueProvider::SetValue](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-ivalueprovider-setvalue).

## See also

[IValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ivalueprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)