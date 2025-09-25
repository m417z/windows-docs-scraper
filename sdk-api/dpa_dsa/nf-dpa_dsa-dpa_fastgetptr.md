# DPA_FastGetPtr macro

## Syntax

```cpp
void DPA_FastGetPtr(
  [in] HDPA hdpa,
  [in] int  i
);
```

## Description

Gets the value of the specified pointer in the dynamic pointer array (DPA).

## Parameters

### `hdpa` [in]

A handle to an existing DPA.

### `i` [in]

The index of the DPA item.

## Remarks

 Unlike function [DPA_GetPtr](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_getptr), the macro **DPA_FastGetPtr** does no parameter validation. If the index specified in **DPA_FastGetPtr** is out of range, the behavior is undefined.