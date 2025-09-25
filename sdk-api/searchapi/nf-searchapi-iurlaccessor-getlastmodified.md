# IUrlAccessor::GetLastModified

## Description

Gets the time stamp identifying when the URL was last modified.

## Parameters

### `pftLastModified` [out]

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)***

Receives a pointer to a variable of type [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) identifying the time stamp when the URL was last modified.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is used to determine whether a URL has changed since the last time it was indexed. If the last modified time has not changed, the indexer does not process the URL's content.

Directory URLs are always processed regardless of the time stamp returned by this method.