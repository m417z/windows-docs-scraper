# MappingRecognizeText function

## Description

Calls upon an ELS service to recognize text. For example, the Microsoft Language Detection service will attempt to recognize the language in which the input text is written.

## Parameters

### `pServiceInfo` [in]

Pointer to a [MAPPING_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_service_info) structure containing information about the service to use in text recognition. The structure must be one of the structures retrieved by a previous call to [MappingGetServices](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappinggetservices). This parameter cannot be set to **NULL**.

### `pszText` [in]

Pointer to the text to recognize. The text must be UTF-16, but some services have additional requirements for the input format. This parameter cannot be set to **NULL**.

### `dwLength` [in]

Length, in characters, of the text specified in *pszText*.

### `dwIndex` [in]

Index inside the specified text to be used by the service. This value should be between 0 and *dwLength*-1. If the application wants to process the entire text, it should set this parameter to 0.

### `pOptions` [in, optional]

Pointer to a [MAPPING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_options) structure containing options that affect the result and behavior of text recognition. The application does not have to specify values for all structure members. This parameter can be set to **NULL** to use the default mapping options.

### `pbag` [in, out]

Pointer to a [MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag) structure in which the service stores its results. On input, the application passes a structure with only the size provided, and the other members set to 0. On output, the structure is filled with information produced by the service during text recognition. This parameter cannot be set to **NULL**.

## Return value

Returns S_OK if successful. The function returns an error HRESULT value if it does not succeed.

## Remarks

The type of text to recognize depends on the service type used by the application. For more information, see [Requesting Text Recognition](https://learn.microsoft.com/windows/desktop/Intl/requesting-text-recognition).

**Warning** The data referred to by *pszText* and *pOptions* must remain valid until the property bag structure passed by *pBag* is freed via

[MappingFreePropertyBag](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingfreepropertybag). This is because both synchronous and asynchronous calls to

**MappingRecognizeText** and [MappingDoAction](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingdoaction) will attempt to use the data passed to the initial

call to **MappingRecognizeText**.

## See also

[Extended Linguistic Services](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services)

[Extended Linguistic Services Functions](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-functions)

[MAPPING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_options)

[MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag)

[MAPPING_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_service_info)

[Requesting Text Recognition](https://learn.microsoft.com/windows/desktop/Intl/requesting-text-recognition)