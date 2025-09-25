# SafeArrayCopy function

## Description

Creates a copy of an existing safe array.

## Parameters

### `psa` [in]

A safe array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

### `ppsaOut` [out]

The safe array descriptor.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* was not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

**SafeArrayCopy** calls the string or variant manipulation functions if the array to copy contains either of these data types. If the array being copied contains object references, the reference counts for the objects are incremented.

## See also

[SysAllocStringLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstringlen)

[VariantCopy](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantcopy)

[VariantCopyInd](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantcopyind)