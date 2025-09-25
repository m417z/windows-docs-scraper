# TextRange_GetText function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Returns the text in a text range, up to a specified number of characters.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `maxLength` [in]

Type: **int**

The number of characters to return, beginning with the character at the starting endpoint of the text range.

### `pRetVal` [out]

Type: **BSTR***

When this function returns, this parameter contains
a pointer to the returned text.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

If *maxLength* is -1, all of the text within the text range is returned.
If *maxLength* is larger than the length of the text range, the returned string contains all of the text in the text range.