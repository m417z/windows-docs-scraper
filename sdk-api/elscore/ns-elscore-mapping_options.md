# MAPPING_OPTIONS structure

## Description

Contains options for text recognition. The values stored in this structure affect the behavior and results of [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext).

## Members

### `Size`

Size of the structure, used to validate the structure version. This value is required.

### `pszInputLanguage`

Optional. Pointer to an input language string, following the IETF naming convention, that identifies the input language that the service should be able to accept. The application can set this member to **NULL** to indicate that the service is free to interpret the input as any input language it supports.

### `pszOutputLanguage`

Optional. Pointer to an output language string, following the IETF naming convention, that identifies the output language that the service should be able to use to produce results. The application can set this member to **NULL** if the service should decide the output language.

### `pszInputScript`

Optional. Pointer to a standard Unicode script name that should be accepted by the service. The application can set this member to **NULL** to let the service decide how handle the input.

### `pszOutputScript`

Optional. Pointer to a standard Unicode script name that the service should use to retrieve results. The application can set this member to **NULL** to let the service decide the output script.

### `pszInputContentType`

Optional. Pointer to a string, following the format of the MIME content types, that identifies the format that the service should be able to interpret when the application passes data. Examples of content types are "text/plain", "text/html", and "text/css". The application can set this member to **NULL** to indicate the "text/plain" content type.

**Note** In Windows 7, the ELS services support only the content type "text/plain". A content type specification can be found at [Text Media Types](https://www.iana.org/assignments/media-types/text).

### `pszOutputContentType`

Optional. Pointer to a string, following the format of the MIME content types, that identifies the format in which the service should retrieve data. The application can set this member to **NULL** to let the service decide the output content type.

### `pszUILanguage`

Reserved.

### `pfnRecognizeCallback`

Optional. Pointer to an application callback function to receive callbacks with the results from the [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext) function. If a callback function is specified, text recognition is executed in asynchronous mode and the application obtains results through the callback function. The application must set this member to **NULL** if text recognition is to be synchronous.

### `pRecognizeCallerData`

Optional. Pointer to private application data passed to the callback function by a service after text recognition is complete. The application must set this member to **NULL** to indicate no private application data.

### `dwRecognizeCallerDataSize`

Optional. Size, in bytes, of any private application data indicated by the **pRecognizeCallerData** member.

### `pfnActionCallback`

Reserved.

### `pActionCallerData`

Reserved.

### `dwActionCallerDataSize`

Reserved.

### `dwServiceFlag`

Optional. Private flag that a service provider defines to affect service behavior. Services can interpret this flag as they require.

**Note** For Windows 7, none of the available ELS services support flags.

### `GetActionDisplayName`

Reserved.

## Remarks

The application does not have to fill in all members of this structure, as services treat **NULL** members as default values. All unused members must be set to 0.

**Warning** The data passed in this structure to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext), as well as data referred to by the *pszText* argument in that call,

must remain valid until the property bag structure passed by *pBag* is freed via

[MappingFreePropertyBag](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingfreepropertybag). This is because both synchronous and asynchronous calls to

**MappingRecognizeText** and [MappingDoAction](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingdoaction) will attempt to use the data passed to the initial

call to **MappingRecognizeText**.

## See also

[Extended Linguistic Services Structures](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-structures)

[MAPPING_DATA_RANGE](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_data_range)

[MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext)