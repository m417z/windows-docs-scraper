# DPA_FastDeleteLastPtr macro

## Syntax

```cpp
void DPA_FastDeleteLastPtr(
  [in] HDPA hdpa
);
```

## Description

Deletes the last pointer from a dynamic pointer array (DPA).

## Parameters

### `hdpa` [in]

A handle to an existing DPA.

## Remarks

If the DPA has no pointers, then the behavior is undefined.