# TextRange_Clone function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Copies a text range.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `pRetVal` [out]

Type: **HUIATEXTRANGE***

When this function returns, contains the copy.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The method never returns **NULL** (Nothing in Microsoft Visual Basic .NET).

The new range can be manipulated independently from the original.