## Description

**CcGetFileSizePointer** returns the size of a file.

## Parameters

### `FO`

[in] Pointer to a file object for the file whose size is to be returned.

## Remarks

The **CcGetFileSizePointer** macro returns a pointer to a member of the cache manager structure for this file that specifies the file size in bytes.

## See also

[**CcSetFileSizes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetfilesizes)