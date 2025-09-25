# FILTERED_DATA_SOURCES structure

## Description

Specifies parameters for a Shell data source for which a filter is loaded.

## Members

### `pwcsExtension`

Pointer to a buffer that contains a file name extension.

### `pwcsMime`

Pointer to a buffer that contains the name of a MIME type.

### `pClsid`

Pointer to a CLSID that identifies the content type.

### `pwcsOverride`

Not implemented.

## Remarks

A filter, also known as a filter handler, is an implementation of the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface.

**FILTERED_DATA_SOURCES** can hold one file content identifier of each type. CLSIDs are always searched first, followed by the file name extension, then MIME type, and finally the path.

## See also

**Conceptual**

[Developing Filter Handlers](https://learn.microsoft.com/windows/desktop/search/-search-ifilter-conceptual)

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)

[ILoadFilter](https://learn.microsoft.com/windows/desktop/api/filtereg/nn-filtereg-iloadfilter)

**Reference**