# DPA_GetPtrPtr macro

## Syntax

```cpp
void DPA_GetPtrPtr(
  [in] HDPA hdpa
);
```

## Description

Gets the pointer to the internal pointer array of a dynamic pointer array (DPA).

## Parameters

### `hdpa` [in]

A handle to an existing DPA.

## Remarks

Applications can use the return value to manipulate the contents of the DPA directly instead of using functions such as [DPA_SetPtr](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_setptr). The return value is invalidated by any operation that changes the number of elements in the DPA or destroys the DPA. For example, after calling function [DPA_InsertPtr](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_insertptr) on a DPA, any internal pointers retrieved by calling the macro **DPA_GetPtrPtr** on the same DPA are no longer valid.