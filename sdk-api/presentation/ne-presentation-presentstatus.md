## Description

## Constants

Defines constants that specify the status of a present.

### `PresentStatus_Queued`

The frame was queued by the system to eventually be shown.

### `PresentStatus_Skipped`

The frame was skipped because a later frame was a better candidate to show.

### `PresentStatus_Canceled`

The frame arrived, but was canceled by the application, so it was not displayed.

## Remarks

The status of a present indicates how it was handled based on timing, and whether it was canceled.

## See also