# ITextInputPanelEventSink::CorrectionModeChanged

## Description

Occurs when the correction comb on the Tablet PC Input Panel has changed modes.

## Parameters

### `oldCorrectionMode` [in]

The previous correction mode, as defined by the [CorrectionMode Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-correctionmode).

### `newCorrectionMode` [in]

The current correction mode, as defined by the [CorrectionMode Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-correctionmode).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

**Note** In Windows 7, this event is no longer raised.

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanelEventSink](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpaneleventsink)

[ITextInputPanelEventSink::CorrectionModeChanging Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-correctionmodechanging)