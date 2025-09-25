# IBrowserService::IEParseDisplayName

## Description

Deprecated. Parses a URL into a pointer to an item identifier list (PIDL).

## Parameters

### `uiCP` [in]

Type: **UINT**

A value of type **UINT** that indicates the code page (for example, CP_ACP, the system default code page) to use in the parsing.

### `pwszPath` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the URL as a Unicode string.

### `ppidlOut` [out]

Type: **LPITEMIDLIST***

The PIDL created from the parsed URL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.