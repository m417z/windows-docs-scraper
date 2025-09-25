# TextPattern_get_DocumentRange function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets the text range for the entire document.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

A control pattern object.

### `pRetVal` [out]

Type: **HUIATEXTRANGE***

When this function returns, contains
the text range spanning the entire document contents of the text container.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.