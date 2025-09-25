# GetThemeStream function

## Description

Retrieves a data stream corresponding to a specified theme, starting from a specified part, state, and property.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to the theme from which the stream will be retrieved.

### `iPartId` [in]

Type: **int**

Specifies the part to retrieve a stream from. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Specifies the state of the part.

### `iPropId` [in]

Type: **int**

Specifies the property to retrieve.

### `ppvStream` [out]

Type: **[VOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)****

Address of a pointer that receives the stream.

### `pcbStream` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer that receives the length, in bytes, of the stream received by *ppvStream*.

### `hInst` [in]

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If *iPropId* is TMT_STREAM, this value is **NULL**. If *iPropId* is TMT_DISKSTREAM, this value is the HINSTANCE of a loaded styles file.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 8:** In high contrast mode, the data stream retrieved by this function is not valid after the *hTheme* theme handle is closed.

The data stream retrieved by this function is not a copy; do not delete or close the data stream after using it.

## See also

[Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states)