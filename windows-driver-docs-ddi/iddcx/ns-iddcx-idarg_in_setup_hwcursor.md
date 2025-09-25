# IDARG_IN_SETUP_HWCURSOR structure

## Description

The **IDARG_IN_SETUP_HWCURSOR** structure is an input parameter passed to [**IddCxMonitorSetupHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetuphardwarecursor) to provide information about new cursors associated with a monitor.

## Members

### `CursorInfo`

[in] An [**IDDCX_CURSOR_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_cursor_caps) structure that provides information about a cursor's capabilities for this path.

### `hNewCursorDataAvailable`

[in] An event handle that will be triggered when new cursor data is available.

## See also

[**CreateEvent**](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa)

[**IddCxMonitorSetupHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetuphardwarecursor)