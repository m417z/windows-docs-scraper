# EngSort function

## Description

The **EngSort** function performs a quick-sort on the specified list.

## Parameters

### `pjBuf` [in, out]

Pointer to the data array to be sorted.

### `c` [in]

Specifies the size, in bytes, of each element in *pjBuf*.

### `cjElem` [in]

Specifies the number of elements in *pjBuf* to be sorted.

### `pfnComp` [in]

Pointer to a function that implements the element comparison to be used for the sort.

## Return value

None

## Remarks

**EngSort** implements a quick-sort algorithm to sort *cjElem* elements in *pjBuf*, where each element is of size *c*. The sorted elements are returned in *pjBuf*; that is, the original contents of the buffer are overwritten with the sorted results.

The basis for comparing two elements is defined in the function that *pfnComp*  points to. This function is prototyped as follows:

```
int (__cdecl *SORTCOMP)(const void *pv1, const void *pv2);
```

where *pv1* and *pv2* point to the two elements to be compared. The return value is the result of the comparison defined as follows:

| Return Value | Meaning |
| --- | --- |
| Negative integer | **pv1* < **pv2* |
| Zero | **pv1* == **pv2* |
| Positive integer | **pv1* > **pv2* |

The array is sorted in increasing order, which is defined by the *pfnComp* parameter.