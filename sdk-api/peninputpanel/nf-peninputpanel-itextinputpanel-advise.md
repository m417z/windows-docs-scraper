# ITextInputPanel::Advise

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Establishes an advisory connection between the Tablet PC Input Panel and the specified sink object.

## Parameters

### `EventSink` [in]

Reference to the sink object to receive event notifications from the Input Panel.

### `EventMask`

A bitwise value of the [EventMask Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-eventmask), indicating the events of interest.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[EventMask Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-eventmask)

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanel::Unadvise Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-unadvise)