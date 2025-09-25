# DPA_Clone function

## Description

[**DPA_Clone** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions.]

Duplicates a dynamic pointer array (DPA).

## Parameters

### `hdpa` [in]

Type: **const HDPA**

A handle to an existing DPA to copy.

### `hdpaNew` [in, out, optional]

Type: **HDPA**

When **NULL**, a new array is copied from *hdpaSource*.

This parameter can also contain an array created with [DPA_Create](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_create) or [DPA_CreateEx](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_createex). The data is overwritten but the original delta size and heap handle retained.

## Return value

Type: **HDPA**

The handle to the new or altered DPA (*hdpaNew*) if successful; otherwise, **NULL**.

## Remarks

**DPA_Clone** is not exported by name or declared in a public header file. To use it, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 331 from ComCtl32.dll to obtain a function pointer.