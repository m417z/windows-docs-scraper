# TextPattern_GetSelection function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets the current range of selected text from a text container supporting the text pattern.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

A control pattern object.

### `pRetVal` [out]

Type: **HUIATEXTRANGE***

When this function returns, contains
the text range spanning the currently selected text in the container.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.