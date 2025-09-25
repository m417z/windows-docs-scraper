# ITextRangeProvider::CompareEndpoints

## Description

Returns a value that specifies whether two text ranges have identical endpoints.

## Parameters

### `endpoint` [in]

Type: **[TextPatternRangeEndpoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textpatternrangeendpoint)**

The endpoint (starting or ending) of the caller's text range.

### `targetRange` [in]

Type: **[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)***

The text range to be compared.

### `targetEndpoint` [in]

Type: **[TextPatternRangeEndpoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textpatternrangeendpoint)**

The endpoint (starting or ending) of the target text range.

### `pRetVal` [out, retval]

Type: **int***

Receives a value that indicates whether the two text ranges have identical endpoints.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Returns a negative value if the caller's endpoint occurs earlier in the text than the target endpoint.

Returns zero if the caller's endpoint is at the same location as the target endpoint.

Returns a positive value if the caller's endpoint occurs later in the text than the target endpoint.

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)