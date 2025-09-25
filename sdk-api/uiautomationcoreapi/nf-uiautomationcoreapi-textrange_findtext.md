# TextRange_FindText function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Returns the first text range in the specified direction that contains the text the client is searching for.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

The text range to search.

### `text` [in]

Type: **BSTR**

The string to search for.

### `backward` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to search backward; otherwise **FALSE**.

### `ignoreCase` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to specify a case-insensitive search; otherwise **FALSE**.

### `pRetVal` [out]

Type: **HUITEXTRANGE***

When this function returns, contains
the text range for the first span of text that matches the string
the client is searching for.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.