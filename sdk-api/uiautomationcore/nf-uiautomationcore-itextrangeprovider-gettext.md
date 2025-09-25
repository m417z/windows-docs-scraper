# ITextRangeProvider::GetText

## Description

Retrieves the plain text of the range.

## Parameters

### `maxLength` [in]

Type: **int**

The maximum length of the string to return. Use -1 if no limit is required.

### `pRetVal` [out, retval]

Type: **BSTR***

Receives the plain text of the text range,
possibly truncated at the specified maximum length. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**ITextRangeProvider::GetText** retrieves both hidden and visible text.

If *maxLength* is greater
than the length of the text span of the caller, the string returned will be the
plain text of the text range.

**ITextRangeProvider::GetText** will not be affected by the order of endpoints in the text flow;
it will always return the text between the start and end endpoints of the text range in the logical text flow order.

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)