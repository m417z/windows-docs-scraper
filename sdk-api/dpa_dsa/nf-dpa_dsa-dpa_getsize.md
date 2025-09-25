# DPA_GetSize function

## Description

Gets the size of a dynamic pointer array (DPA).

## Parameters

### `hdpa` [in]

Type: **HDPA**

A handle to an existing DPA.

## Return value

Type: **[ULONGLONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the size of the DPA, including the internal bookkeeping information. If *pdpa* is **NULL**, the function returns zero.