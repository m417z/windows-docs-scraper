# PropVariantClear function

## Description

The **PropVariantClear** function
frees all elements that can be freed in a given
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. For complex elements with known element pointers, the underlying elements are freed prior to freeing the containing element.

## Parameters

### `pvar` [in]

A pointer to an initialized
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure for which any deallocatable elements are to be freed. On return, all zeroes are written to the
**PROPVARIANT** structure.

## Return value

This function returns HRESULT.

## Remarks

At any level of indirection, **NULL** pointers are ignored. For example, the *pvar* parameter points to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure of type **VT_CF**. The **pclipdata** member of the **PROPVARIANT** structure points to a **CLIPDATA** structure. The *pClipData* pointer in the **CLIPDATA** structure is **NULL**. In this example, the *pClipData* pointer is ignored. However, the **CLIPDATA** structure pointed to by the **pclipdata** member of the **PROPVARIANT** structure is freed.

On return, this function writes zeroes to the specified
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure, so the VT-type is **VT_EMPTY**.

Passing **NULL** as the *pvar* parameter produces a return code of S_OK.

**Note** Do not use this function to initialize
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures. Instead, initialize these structures using the
[PropVariantInit](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantinit) macro (defined in Propidl.h).

## See also

[FreePropVariantArray](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-freepropvariantarray)