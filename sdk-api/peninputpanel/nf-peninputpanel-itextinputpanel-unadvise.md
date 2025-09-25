# ITextInputPanel::Unadvise

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Terminates an advisory connection previously established through [ITextInputPanel::Advise Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-advise).

## Parameters

### `EventSink` [in]

Reference to the sink object currently receiving event notifications from the Input Panel.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanel::Advise Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-advise)