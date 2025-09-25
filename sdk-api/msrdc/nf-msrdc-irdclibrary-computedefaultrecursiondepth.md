# IRdcLibrary::ComputeDefaultRecursionDepth

## Description

The
**ComputeDefaultRecursionDepth**
method computes the maximum level of recursion for the specified file size. The depth returned
by the method may be larger than **MSRDC_MAXIMUM_DEPTH**. The caller must compare the value
returned through the *depth* parameter with
**MSRDC_MAXIMUM_DEPTH**.

## Parameters

### `fileSize` [in]

The approximate size of the file.

### `depth` [out]

Pointer to a **ULONG** that will receive the suggested maximum recursion
depth.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdclibrary)