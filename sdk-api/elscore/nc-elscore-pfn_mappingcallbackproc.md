# PFN_MAPPINGCALLBACKPROC callback function

## Description

An application-defined callback function that asynchronously processes data produced by the [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext) function. The **MAPPINGCALLBACKPROC** type defines a pointer to this callback function. **MappingCallbackProc** is a placeholder for the application-defined function name.

## Parameters

### `pBag` [in]

Pointer to a [MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag) structure containing the results of the call to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext).

### `data` [in]

Pointer to private application data. This pointer is the same as that passed in the **pRecognizeCallerData** member of the [MAPPING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_options) structure.

### `dwDataSize` [in]

Size, in bytes, of the private application data. This size is the same as that passed in the **dwRecognizeCallerDataSize** member of the [MAPPING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_options) structure when the application calls [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext) asynchronously.

### `Result` [in]

Return code from [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext). The return code is S_OK if the function succeeded, or an error code otherwise.

## Remarks

A **MappingCallbackProc** function consumes the results retrieved by [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext). The application registers the callback function by passing its address to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext) in a [MAPPING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_options) structure.

The application should check the *Result* parameter before using the data in the *pBag* parameter. When it is done using the data from the property bag, the application must call [MappingFreePropertyBag](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingfreepropertybag) because the property bag can contain pointers into the original text. For more information about the property bag, see the remarks for the [MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag) structure.

## See also

[Extended Linguistic Services](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services)

[Extended Linguistic Services Functions](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-functions)

[MAPPING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_options)

[MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag)

[MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext)

[Providing Callbacks for ELS Services](https://learn.microsoft.com/windows/desktop/Intl/providing-callbacks-for-els-services)