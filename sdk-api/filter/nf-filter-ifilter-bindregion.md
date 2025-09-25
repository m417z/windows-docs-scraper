# IFilter::BindRegion

## Description

Retrieves an interface representing the specified portion of object. Currently reserved for future use.

## Parameters

### `origPos` [in]

A [FILTERREGION](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-filterregion) structure that contains the position of the text.

### `riid` [in]

A reference to the requested interface identifier.

### `ppunk` [out]

A pointer to a variable that receives the interface pointer requested in *riid*. Upon successful return, **ppunk* contains the requested interface pointer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_NOTIMPL** | This method is not currently implemented. |
| **FILTER_W_REGION_CLIPPED** | The filter could not bind the entire region. |

## Remarks

If it is impossible for the **BindRegion** method to bind an interface to the specified region, return FILTER_W_REGION_CLIPPED. This situation can occur when the next such chunk is in a linked object or an embedded object.

Not all filters are capable of supporting the **BindRegion** method in a rational way. Filters that are implemented by viewing applications will benefit the most from this method. The method is intended to be a way to pass cookies through the search engine and back to the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface implementation.

### Notes to Implementers

This method is currently reserved for future use. Always return E_NOTIMPL.

## See also

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)