# IBrowserService::IEGetDisplayName

## Description

Deprecated. Retrieves the URL that corresponds to a pointer to an item identifier list (PIDL).

## Parameters

### `pidl` [in]

Type: **LPCITEMIDLIST**

The PIDL for which to get the corresponding URL.

### `pwszName` [out]

Type: **LPWSTR**

A pointer to a buffer of at least INTERNET_MAX_URL_LENGTH characters to receive the URL.

### `uFlags` [in]

Type: **UINT**

One of the following values specifying the form of the retrieved URL.

#### SHGDN_NORMAL (0)

The URL is relative to the folder from which the request was made. SHGDN_NORMAL is equivalent to **NULL** and therefore should not be combined with other flags.

#### SHGDN_FORADDRESSBAR (0)

The URL is suitable for display in an address bar combo box.

#### SHGDN_FORPARSING (0)

The URL can be used for parsing.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.