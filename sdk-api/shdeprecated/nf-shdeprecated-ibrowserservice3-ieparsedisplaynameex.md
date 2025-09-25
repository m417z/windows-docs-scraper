# IBrowserService3::IEParseDisplayNameEx

## Description

Deprecated. Parses a URL into a pointer to an item identifier list (PIDL).

## Parameters

### `uiCP`

Type: **UINT**

The code page (for example, CP_ACP, the system default code page).

### `pwszPath`

Type: **LPCWSTR**

A pointer to a buffer containing the URL to parse, as a Unicode string.

### `dwFlags`

Type: **DWORD**

The following value, if desired.

#### IEPDN_BINDINGUI (0x00000001)

Display a UI element during binding.

### `ppidlOut`

Type: **LPITEMIDLIST***

The PIDL created from the parsed URL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method replaces [IEParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-ieparsedisplayname).