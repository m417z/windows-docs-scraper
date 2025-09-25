# DPA_AppendPtr macro

## Syntax

```cpp
int DPA_AppendPtr(
   HDPA hdpa,
   void *pitem
);
```

## Return value

Type: **int**

Returns the index of the new item or `-1`, if the append action fails.

## Description

Inserts a new item at the end of a dynamic pointer array (DPA).

## Parameters

### `hdpa`

A handle to a DPA.

### `pitem`

A pointer to the item that is to be inserted.

## Remarks

**Note** This macro wraps the [DPA_InsertPtr](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_insertptr) function.