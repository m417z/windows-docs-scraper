# EvtCreateBookmark function

## Description

Creates a bookmark that identifies an event in a channel.

## Parameters

### `BookmarkXml` [in, optional]

 An XML string that contains the bookmark or **NULL** if creating a bookmark.

## Return value

A handle to the bookmark if the call succeeds; otherwise, **NULL**. If **NULL**, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

 To create a bookmark, set the *BookmarkXml* parameter to **NULL**. Before you exit, call the [EvtUpdateBookmark](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtupdatebookmark) function to update the bookmark. Pass the bookmark handle to the [EvtRender](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtrender) function to render the bookmark as an XML string. You can then persist the string for use later. To begin consuming events from where you left off the last time, set *BookmarkXml* to the XML string that you persisted. For a subscription, pass the bookmark handle to the [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) function. For a query, pass the bookmark handle to the [EvtSeek](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtseek) function to seek to a specific event in the query result.

If the query is against multiple channels, the bookmark handle will contain bookmarks for each channel. You cannot create a bookmark for a log file.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the handle when done.

#### Examples

For an example that shows how to use this function, see [Bookmarking Events](https://learn.microsoft.com/windows/desktop/WES/bookmarking-events).

## See also

[EvtUpdateBookmark](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtupdatebookmark)