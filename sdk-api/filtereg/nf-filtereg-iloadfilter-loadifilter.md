# ILoadFilter::LoadIFilter

## Description

Retrieves and loads the most appropriate filter that is mapped to a Shell data source.

## Parameters

### `pwcsPath` [in]

Pointer to a comma-delimited null-terminated Unicode string buffer that specifies the path of the file to be filtered. This parameter can be null.

### `pFilteredSources` [in]

Pointer to the [FILTERED_DATA_SOURCES](https://learn.microsoft.com/windows/desktop/api/filtereg/ns-filtereg-filtered_data_sources) structure that specifies parameters for a Shell data source for which a filter is loaded. This parameter cannot be null.

### `pUnkOuter` [in]

If the object is being created as part of an aggregate, specify a pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the aggregate.

### `fUseDefault` [in]

If **TRUE**, use the default filter; if **FALSE**, proceed with the most appropriate filter that is available.

### `pFilterClsid` [in, out]

Pointer to the CLSID (CLSID_FilterRegistration) that receives the class identifier of the returned filter.

### `SearchDecSize` [in, out]

Not implemented.

### `pwcsSearchDesc` [in, out]

Not implemented.

### `ppIFilt` [in, out]

The address of a pointer to an implementation of an [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface that **LoadIFilter** selects.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A filter, also known as a filter handler, is an implementation of the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface.

**ILoadFilter** attempts to load a filter that can process a Shell data source of the type specified in the *pFilteredSources* parameter through the *pwcsPath* parameter.If an appropriate filter for the data source is not found, and *fUseDefault* is **false**, this method returns null in the *ppIFilt* parameter. If an appropriate filter for the data source is not found, and *fUseDefault* is **true**, the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface on the default **IFilter** is returned in the *ppIFilt* parameter.

## See also

[ILoadFilter](https://learn.microsoft.com/windows/desktop/api/filtereg/nn-filtereg-iloadfilter)