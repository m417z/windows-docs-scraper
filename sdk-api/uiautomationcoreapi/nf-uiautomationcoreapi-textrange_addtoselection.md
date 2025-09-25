# TextRange_AddToSelection function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Adds to the existing collection of highlighted text in a text container
that supports multiple, disjoint selections by highlighting supplementary text
corresponding to the calling text range *Start*
and *End* endpoints.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.