# EvtUpdateBookmark function

## Description

Updates the bookmark with information that identifies the specified event.

## Parameters

### `Bookmark` [in]

The handle to the bookmark to be updated. The [EvtCreateBookmark](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreatebookmark) function returns this handle.

### `Event` [in]

The handle to the event to bookmark.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code. |

## See also

[EvtCreateBookmark](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreatebookmark)