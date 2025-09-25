# ITextInputPanelEventSink::InputAreaChanged

## Description

Occurs when the input area has changed on the Tablet PC Input Panel.

## Parameters

### `oldInputArea` [in]

The previous input area as defined by the [PanelInputArea Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-panelinputarea).

### `newInputArea` [in]

The current input area as defined by the [PanelInputArea Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-panelinputarea).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanelEventSink](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpaneleventsink)

[ITextInputPanelEventSink::InputAreaChanging Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-inputareachanging)