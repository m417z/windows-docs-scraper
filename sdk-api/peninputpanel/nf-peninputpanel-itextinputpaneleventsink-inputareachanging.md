# ITextInputPanelEventSink::InputAreaChanging

## Description

Occurs when the input area is about to change on the Tablet PC Input Panel.

## Parameters

### `oldInputArea` [in]

The current input area as defined by the [PanelInputArea Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-panelinputarea).

### `newInputArea` [in]

The input area the Input Panel is changing to as defined by the [PanelInputArea Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-panelinputarea).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanelEventSink](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpaneleventsink)

[ITextInputPanelEventSink::InputAreaChanged Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-inputareachanged)