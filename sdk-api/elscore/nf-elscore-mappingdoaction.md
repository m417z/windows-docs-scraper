# MappingDoAction function

## Description

Causes an ELS service to perform an action after text recognition has occurred. For example, a phone dialer service first must recognize phone numbers and then can perform the "action" of dialing a number.

## Parameters

### `pBag` [in, out]

Pointer to a [MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag) structure containing the results of a previous call to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext). This parameter cannot be set to **NULL**.

### `dwRangeIndex` [in]

A starting index inside the text recognition results for a recognized text range. This value should be between 0 and the range count.

### `pszActionId` [in]

Pointer to the identifier of the action to perform. This parameter cannot be set to **NULL**.

## Return value

Returns S_OK if successful. The function returns an error HRESULT value if it does not succeed.

## Remarks

The application must precede the call to **MappingDoAction** with a call to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext).

**Warning** The data referred to by the *pszText* and *pOptions* arguments passed to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext)

must remain valid until the property bag structure passed by *pBag* is freed via

[MappingFreePropertyBag](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingfreepropertybag). This is because both synchronous and asynchronous calls to

**MappingRecognizeText** and **MappingDoAction** will attempt to use the data passed to the initial

call to **MappingRecognizeText**.

## See also

[Extended Linguistic Services](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services)

[Extended Linguistic Services Functions](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-functions)

[MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag)

[MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext)