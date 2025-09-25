# ITextInputPanelEventSink::InPlaceStateChanged

## Description

Occurs when the In-Place state has changed.

## Parameters

### `oldInPlaceState` [in]

The current state, as defined by the [InPlaceState Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-inplacestate).

### `newInPlaceState` [in]

The new state that the Input Panel has changed to, as defined by the [InPlaceState Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-inplacestate).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanelEventSink](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpaneleventsink)

[ITextInputPanelEventSink::InPlaceStateChanging Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-inplacestatechanging)