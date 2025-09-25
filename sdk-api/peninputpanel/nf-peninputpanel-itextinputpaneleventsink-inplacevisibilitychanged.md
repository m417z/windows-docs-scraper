# ITextInputPanelEventSink::InPlaceVisibilityChanged

## Description

Occurs when the Tablet PC Input Panel has switched between visible and invisible.

## Parameters

### `oldVisible` [in]

**TRUE** if the Input Panel has changed from visible to invisible, otherwise **FALSE**.

### `newVisible` [in]

**TRUE** if the Input Panel has changed from invisible to visible, otherwise **FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanelEventSink](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpaneleventsink)

[ITextInputPanelEventSink::InPlaceVisibilityChanging Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-inplacevisibilitychanging)