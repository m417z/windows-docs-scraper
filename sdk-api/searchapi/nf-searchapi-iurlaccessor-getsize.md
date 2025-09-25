# IUrlAccessor::GetSize

## Description

Gets the size of the content designated by the URL.

## Parameters

### `pllSize` [out]

Type: **ULONGLONG***

Receives a pointer to the
number of bytes of data contained in the URL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The value calculated in this method is a factor in determining limitations on [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) output size. This method should return 0 for containers if the protocol implementation is for a hierarchical content source.

Implement this method for non-files by returning the size of the document to be indexed. For example, to index a database where each row is a document, return the best estimate of the size of the row.