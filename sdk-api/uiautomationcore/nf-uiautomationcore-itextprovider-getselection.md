# ITextProvider::GetSelection

## Description

Retrieves a collection of text ranges that represents the currently selected text in a text-based control.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives the address of an array of pointers to the [ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider) interfaces of the text ranges,
one for each selected span of text. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For UI Automation providers that support text selection,
the provider should implement this method and also return a [ITextProvider::SupportedTextSelection](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-itextprovider-get_supportedtextselection) value.

If the control contains only a single span of selected text, the *pRetVal* array should contain a single text range.

If the control contains a text insertion point but no text is selected, the *pRetVal* array should contain a degenerate (empty) text range at the position of the text insertion point.

 If the control contains no selected text, or if the control does not contain a text insertion point, set *pRetVal* to **NULL**.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)