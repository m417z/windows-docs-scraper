# EvtSeek function

## Description

Seeks to a specific event in a query result set.

## Parameters

### `ResultSet` [in]

The handle to a query result set that the [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) function returns.

### `Position` [in]

The zero-based offset to an event in the result set. The flag that you specify in the *Flags* parameter indicates the beginning relative position in the result set from which to seek. For example, you can seek from the beginning of the results or from the end of the results. Set to 0 to move to the relative position specified by the flag.

### `Bookmark` [in]

A handle to a bookmark that the [EvtCreateBookmark](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreatebookmark) function returns. The bookmark identifies an event in the result set to which you want to seek. Set this parameter only if the *Flags* parameter has the EvtSeekRelativeToBookmark flag set.

### `Timeout` [in]

 Reserved. Must be zero.

### `Flags` [in]

One or more flags that indicate the relative position in the result set from which to seek. For possible values, see the [EVT_SEEK_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_seek_flags) enumeration.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function was successful. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

You can use this function only on result sets from an Admin or Operational channel, or from .evtx log files.

#### Examples

For an example that shows how to use this function, see [Bookmarking Events](https://learn.microsoft.com/windows/desktop/WES/bookmarking-events).

## See also

[EvtNext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnext)

[EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery)