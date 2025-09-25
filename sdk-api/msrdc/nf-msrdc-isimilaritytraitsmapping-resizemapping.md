# ISimilarityTraitsMapping::ResizeMapping

## Description

Resizes the file mapping object for a similarity traits table file.

## Parameters

### `accessMode` [in]

[RdcMappingAccessMode](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdcmappingaccessmode) enumeration value that specifies the desired access to the file mapping object.

### `begin` [in]

File offset, in bytes, where the file mapping is to begin.

### `end` [in]

File offset, in bytes, where the file mapping is to end.

### `actualEnd` [out]

Pointer to a location that receives the file offset, in bytes, of the actual end of the file mapping, rounded up to the nearest block size.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISimilarityTraitsMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitsmapping)