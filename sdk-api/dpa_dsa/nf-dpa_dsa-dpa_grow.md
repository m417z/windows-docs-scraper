# DPA_Grow function

## Description

Changes the number of pointers in a dynamic pointer array (DPA).

## Parameters

### `pdpa` [in]

Type: **HDPA**

A handle to an existing DPA.

### `cp` [in]

Type: **int**

The number of pointers desired in the DPA.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

If *cp* is less than the number of pointers already in the DPA, the DPA is left unchanged. If *cp* is greater than the number of pointers in the DPA, the added pointers are initialized to **NULL**.