# ITextInputPanelEventSink::CorrectionModeChanging

## Description

Occurs when the correction comb on the Tablet PC Input Panel is about to change modes.

## Parameters

### `oldCorrectionMode` [in]

The current correction mode, as defined by the [CorrectionMode Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-correctionmode).

### `newCorrectionMode` [in]

The correction mode the Input Panel is changing to, as defined by the [CorrectionMode Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-correctionmode).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

**Note** In Windows 7, this event no longer is raised.

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanelEventSink](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpaneleventsink)

[ITextInputPanelEventSink::CorrectionModeChanged Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-correctionmodechanged)