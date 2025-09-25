# IBrowserService2::v_GetViewStream

## Description

Deprecated. Returns a stream used to load or save the view state.

## Parameters

### `pidl`

Type: **LPCITEMIDLIST**

A PIDL that identifies the view.

### `grfMode`

Type: **DWORD**

Not used.

### `pwszName`

Type: **LPCWSTR**

A pointer to a buffer that contains the Unicode name of the window.

## Return value

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)**

Stream that can be used to load or save the view state.