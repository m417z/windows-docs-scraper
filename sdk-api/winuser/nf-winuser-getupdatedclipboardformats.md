# GetUpdatedClipboardFormats function

## Description

Retrieves the currently supported clipboard formats.

## Parameters

### `lpuiFormats` [out]

Type: **PUINT**

An array of clipboard formats. For a description of the standard clipboard formats, see [Standard Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/standard-clipboard-formats).

### `cFormats` [in]

Type: **UINT**

The number of entries in the array pointed to by *lpuiFormats*.

### `pcFormatsOut` [out]

Type: **PUINT**

The actual number of clipboard formats in the array pointed to by *lpuiFormats*.

## Return value

Type: **BOOL**

The function returns **TRUE** if successful; otherwise, **FALSE**. Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for additional details.