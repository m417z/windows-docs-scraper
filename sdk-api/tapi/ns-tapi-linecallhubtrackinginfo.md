# LINECALLHUBTRACKINGINFO structure

## Description

The
**LINECALLHUBTRACKINGINFO** structure contains information that reports the type of tracking available to a call hub. This structure is exposed only to applications that negotiate a TAPI version of 2.2 or higher.

The
[TSPI_lineSetCallHubTracking](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetcallhubtracking) function and the
[TSPI_lineGetCallHubTracking](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallhubtracking) function use the
**LINECALLHUBTRACKINGINFO** structure.

## Members

### `dwTotalSize`

Total size, in bytes.

### `dwNeededSize`

Size needed, in bytes.

### `dwUsedSize`

Size used, in bytes.

### `dwAvailableTracking`

Available tracking, as represented by a
[LINECALLHUBTRACKING](https://learn.microsoft.com/windows/desktop/Tapi/linecallhubtracking--constants).constant.

### `dwCurrentTracking`

Current tracking, as represented by a [LINECALLHUBTRACKING](https://learn.microsoft.com/windows/desktop/Tapi/linecallhubtracking--constants) constant.

## See also

[LINECALLHUBTRACKING](https://learn.microsoft.com/windows/desktop/Tapi/linecallhubtracking--constants)

[TSPI_lineGetCallHubTracking](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallhubtracking)

[TSPI_lineSetCallHubTracking](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetcallhubtracking)