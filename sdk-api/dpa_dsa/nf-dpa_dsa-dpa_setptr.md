# DPA_SetPtr function

## Description

[**DPA_SetPtr** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Assigns a value to an item in a dynamic pointer array (DPA).

## Parameters

### `hdpa`

Type: **HDPA**

A handle to a DPA.

### `i`

Type: **int**

The index of the item in the DPA.

**Note** If the index is beyond the current size of the DPA, the DPA expands to accommodate it. You do not need to assign items contiguously.

### `p`

Type: **void***

A pointer to the value to assign to the specified DPA item.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.