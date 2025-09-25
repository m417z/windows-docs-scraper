# DSA_Clone function

## Description

Duplicates a dynamic structure array (DSA).

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to an existing DSA.

## Return value

Type: **HDSA**

Returns a handle to the clone, or **NULL** if the operation fails.

## Remarks

The clone consists of a copy of the structures stored in the original DSA. Subsequent changes to the original DSA do not affect the clone.