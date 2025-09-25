# ITextProvider::get_SupportedTextSelection

## Description

Retrieves a value that specifies the type of text selection that is supported by the control.

This property is read-only.

## Parameters

*pRetVal*

Type: **[SupportedTextSelection](https://learn.microsoft.com/windows/win32/api/uiautomationcore/ne-uiautomationcore-supportedtextselection)\***

When this function returns, contains a pointer to the [SupportedTextSelection](https://learn.microsoft.com/windows/win32/api/uiautomationcore/ne-uiautomationcore-supportedtextselection) object.

## Syntax

```cpp
HRESULT get_SupportedTextSelection (SupportedTextSelection *pRetVal);
```

## Remarks

> ### Parameters
>
> `pRetVal` [out]
>
> Type: **[SupportedTextSelection](https://learn.microsoft.com/windows/win32/api/uiautomationcore/ne-uiautomationcore-supportedtextselection)\***
>
> When this function returns, contains a pointer to the [SupportedTextSelection](https://learn.microsoft.com/windows/win32/api/uiautomationcore/ne-uiautomationcore-supportedtextselection) object.

## See also

[ITextProvider interface](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider), [ITextRangeProvider interface](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider), [UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)