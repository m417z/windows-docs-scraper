# TextRange_Compare function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Compares two text ranges.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

The first text range to compare.

### `range` [in]

Type: **HUIATEXTRANGE**

The second text range to compare.

### `pRetVal` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

When this function returns, contains **TRUE** if the two objects span the same text; otherwise **FALSE**.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.