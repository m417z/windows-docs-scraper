# IUIAutomationTextRange::CompareEndpoints

## Description

Retrieves a value that specifies whether the start or end endpoint of this text range is the same as the start or end endpoint of another text range.

## Parameters

### `srcEndPoint` [in]

Type: **[TextPatternRangeEndpoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textpatternrangeendpoint)**

A value indicating whether the start or end endpoint of this text range is to be compared.

### `range` [in]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)***

A pointer to the text range to compare.

### `targetEndPoint` [in]

Type: **[TextPatternRangeEndpoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textpatternrangeendpoint)**

A value indicating whether the start or end endpoint of *range* is to be compared.

### `compValue` [out, retval]

Type: **int***

Receives a negative value if the caller's endpoint occurs earlier in the text than the target endpoint; 0 if the caller's endpoint is at the same location as the target endpoint; or a positive value if the caller's endpoint occurs later in the text than the target endpoint.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)