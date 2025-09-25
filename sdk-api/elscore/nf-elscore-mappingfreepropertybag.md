# MappingFreePropertyBag function

## Description

Frees memory and resources allocated during an ELS text recognition operation.

## Parameters

### `pBag` [in]

Pointer to a [MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag) structure containing the properties for which to free resources. This parameter cannot be set to **NULL**.

## Return value

Returns S_OK if successful. The function returns an error HRESULT value if it does not succeed.

## Remarks

An ELS service allocates memory and resources for data retrieved from application calls to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext). The **MappingFreePropertyBag** function releases these resources.

**Caution** Services should not be freed before freeing the property bags produced by those services.

**Caution** The application must call this function only once for each call to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext) when the property bag is no longer needed. Not calling **MappingFreePropertyBag** after each call to **MappingRecognizeText** causes a resource leak. For more information about memory allocation for the property bag, see the remarks for the [MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag) structure.

## See also

[Extended Linguistic Services](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services)

[Extended Linguistic Services Functions](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-functions)

[MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag)

[MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext)

[Requesting Text Recognition](https://learn.microsoft.com/windows/desktop/Intl/requesting-text-recognition)