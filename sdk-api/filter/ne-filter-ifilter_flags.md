# IFILTER_FLAGS enumeration

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Indicates whether the caller should use the **IPropertySetStorage** and **IPropertyStorage** interfaces to locate additional properties.

## Constants

### `IFILTER_FLAGS_OLE_PROPERTIES:1`

The caller should use the [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) and [IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interfaces to locate additional properties. When this flag is set, properties available through COM enumerators should not be returned from [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter).

## Remarks

The *pdwFlags* parameter in the [IFilter::Init](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-init) method allows the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) implementation to pass information back to the caller. For Indexing Service 3.0, the only valid flag is IFILTER_FLAGS_OLE_PROPERTIES. If OLE properties should not be enumerated, then pdwFlags should be set to zero.

## See also

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)

[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)