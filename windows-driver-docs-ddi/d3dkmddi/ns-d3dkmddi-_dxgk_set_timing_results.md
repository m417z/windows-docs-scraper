# _DXGK_SET_TIMING_RESULTS structure

## Description

Structure to report result flags from the SetTiming call which apply to the complete call rather than individual paths.

## Members

### `ConnectionStatusChanges`

If set, indicates that one or more connector status changes were detected in the course of this call so the OS needs to call DxgkDdiQueryConnectionStatus to catch up with all changes and to resync with the current state.

**Note** This flag is intended to indicate to the OS that a change in available displays has occurred so TargetStatus* and MonitorStatus* changes should cause the driver to set the flag whereas LinkConfiguration* changes should be reported but should not cause the flag to be set. Any update to an active path requires that a LinkConfiguration* change be reported so that the status of the change can be distinguished from previous changes with the same result so including these changes in the flag would not provide useful information.

### `Reserved`

This value is reserved for system use.

### `Value`

UINT used to operate on the combined bit-fields.