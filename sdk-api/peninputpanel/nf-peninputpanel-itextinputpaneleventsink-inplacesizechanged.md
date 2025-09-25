# ITextInputPanelEventSink::InPlaceSizeChanged

## Description

Occurs when the in-place Input Panel size has changed due to a user resize, auto growth, or an input area change.

## Parameters

### `oldBoundingRectangle` [in]

The bounding rectangle that represents the previous size of the Input Panel.

### `newBoundingRectangle` [in]

The bounding rectangle that represents the current size of the Input Panel.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Actions causing the Input Panel to change size include changing the screen resolution or DPI settings, rotating the tablet screen, changing the input language, the user explicitly resizing the Input Panel, and changing the theme.

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanelEventSink](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpaneleventsink)

[ITextInputPanelEventSink::InPlaceSizeChanging Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-inplacesizechanging)