# IRichEditOle::ContextSensitiveHelp

## Description

Indicates if a rich edit control should transition into or out of context-sensitive help mode. A rich edit control calls the **IRichEditOle::ContextSensitiveHelp** method of any in-place object which is currently active if a state change is occurring.

## Parameters

### `fEnterMode`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicator of whether the control is entering context-sensitive help mode (**TRUE**) or leaving it (**FALSE**).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)