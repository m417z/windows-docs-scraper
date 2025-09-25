# IUIAutomationTextRange::MoveEndpointByRange

## Description

Moves one endpoint of the current text range to the specified endpoint of a second text range.

## Parameters

### `srcEndPoint` [in]

Type: **[TextPatternRangeEndpoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textpatternrangeendpoint)**

An endpoint (either start or end) of the current text range. This is the endpoint to be moved.

### `range` [in]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)***

A second text range from the same text provider as the current text range.

### `targetEndPoint` [in]

Type: **[TextPatternRangeEndpoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textpatternrangeendpoint)**

An endpoint (either start or end) of the second text range. The *srcEndPoint* of the current text range is moved to this endpoint.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the endpoint being moved crosses the other endpoint of the same text range, that other endpoint is moved also, resulting in a degenerate (empty) range and ensuring the correct ordering of the endpoints (that is, the start is always less than or equal to the end).

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)