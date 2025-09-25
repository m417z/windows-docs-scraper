# ITextInputPanelEventSink::TextInserted

## Description

Occurs when the Tablet PC Input Panel has inserted text into the control with input focus. Provides access to the ink the user entered in the Input Panel.

## Parameters

### `Ink` [in]

Array of [Ink](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) objects in the Input Panel.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

There is a minimum of one [Ink](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object for each line of the Input Panel containing text at the time of insertion.

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanelEventSink](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpaneleventsink)

[ITextInputPanelEventSink::TextInserting Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-textinserting)