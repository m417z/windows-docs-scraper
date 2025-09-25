# EventMask enumeration

## Description

The events on the [ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) that you can set attention for.

## Constants

### `EventMask_InPlaceStateChanging:1`

Occurs when the correction mode is about to change.

### `EventMask_InPlaceStateChanged:2`

Occurs when the correction mode has changed.

### `EventMask_InPlaceSizeChanging:4`

Occurs when the in-place Input Panel size is about to change due to user resizing, auto growth or an input area change.

### `EventMask_InPlaceSizeChanged:8`

Occurs when the in-place Input Panel size has changed due to a user resize, auto growth, or an input area change.

### `EventMask_InputAreaChanging:16`

Occurs when the input area is about to change.

### `EventMask_InputAreaChanged:32`

Occurs when the input area has changed.

### `EventMask_CorrectionModeChanging:64`

Occurs when the correction mode is about to change.

### `EventMask_CorrectionModeChanged:128`

Occurs when the correction mode has changed.

### `EventMask_InPlaceVisibilityChanging:256`

Occurs when the in-place Input Panel visibility is about to change.

### `EventMask_InPlaceVisibilityChanged:512`

Occurs when the input area has changed.

### `EventMask_TextInserting:1024`

Occurs when Tablet PC Input Panel is about to insert text into the control with input focus.

### `EventMask_TextInserted:2048`

Occurs when the Tablet PC Input Panel has inserted text into the control with input focus.

### `EventMask_All`

Represents a bitwise combination of all member events.

## See also

[ITextInputPanel::Advise Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-advise)