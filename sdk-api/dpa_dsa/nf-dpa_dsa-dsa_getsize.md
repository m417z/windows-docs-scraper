# DSA_GetSize function

## Description

Gets the size of the dynamic structure array (DSA).

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to an existing DSA.

## Return value

Type: **[ULONGLONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the size of the DSA, including the internal bookkeeping information, in bytes. If *hdsa* is **NULL**, the function returns zero.