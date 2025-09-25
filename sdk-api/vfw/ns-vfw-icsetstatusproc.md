# ICSETSTATUSPROC structure

## Description

The **ICSETSTATUSPROC** structure contains status information used with the [ICM_SET_STATUS_PROC](https://learn.microsoft.com/windows/desktop/Multimedia/icm-set-status-proc) message.

## Members

### `dwFlags`

Reserved; set to zero.

### `lParam`

Parameter that contains a constant to pass to the status procedure.

### `Status`

#### - fpfnStatus

Pointer to the status function. Specify **NULL** if status messages should not be sent. For more information about the callback function, see the [MyStatusProc](https://learn.microsoft.com/previous-versions/dd743620(v=vs.85)) function.

## See also

[ICM_SET_STATUS_PROC](https://learn.microsoft.com/windows/desktop/Multimedia/icm-set-status-proc)

[MyStatusProc](https://learn.microsoft.com/previous-versions/dd743620(v=vs.85))

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)