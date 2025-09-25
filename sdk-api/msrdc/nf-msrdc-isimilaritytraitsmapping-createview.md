# ISimilarityTraitsMapping::CreateView

## Description

Maps a view of the file mapping for a similarity traits table file.

## Parameters

### `minimumMappedPages` [in]

Minimum number of pages of the file mapping to map to the view.

### `accessMode` [in]

[RdcMappingAccessMode](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdcmappingaccessmode) enumeration value that specifies the desired access to the file mapping object.

### `mappedView` [out]

Pointer to a location that will receive the returned [ISimilarityTraitsMappedView](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitsmappedview) interface pointer. Callers must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Data accessed through read-only views will never be modified.

## See also

[ISimilarityTraitsMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitsmapping)