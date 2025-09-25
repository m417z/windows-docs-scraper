# MAPPING_DATA_RANGE structure

## Description

Contains text recognition results for a recognized text subrange. An array of structures of this type is retrieved by an Extended Linguistic Services (ELS) service in a [MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag) structure.

## Members

### `dwStartIndex`

Index of the beginning of the subrange in the text, where 0 indicates the character at the pointer passed to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext), instead of an offset to the index passed to the function in the *dwIndex* parameter. The value should be less than the entire length of the text.

### `dwEndIndex`

Index of the end of the subrange in the text, where 0 indicates the character at the pointer passed to [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext), instead of an offset to the index passed to the function in the *dwIndex* parameter. The value should be less than the entire length of the text.

### `pszDescription`

Reserved.

### `dwDescriptionLength`

Reserved.

### `pData`

Pointer to data retrieved as service output associated with the subrange. This data must be of the format indicated by the content type supplied in the **pszContentType** member.

### `dwDataSize`

Size, in bytes, of the data specified in **pData**. Each service is required to report its output data size in bytes.

### `pszContentType`

Optional. Pointer to a string specifying the MIME content type of the data indicated by **pData**. Examples of content types are "text/plain", "text/html", and "text/css".

**Note** In Windows 7, the ELS services support only the content type "text/plain". A content type specification can be found at [Text Media Types](https://www.iana.org/assignments/media-types/text).

### `prgActionIds`

Available action Ids for this subrange. They are usable for calling [MappingDoAction](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingdoaction).

**Note** In Windows 7, the ELS services do not expose any actions.

### `dwActionsCount`

The number of available actions for this subrange.

**Note** In Windows 7, the ELS services do not expose any actions.

### `prgActionDisplayNames`

Action display names for this subrange. These strings can be localized.

**Note** In Windows 7, the ELS services do not expose any actions.

## Remarks

**Note** The application should not alter any of the members of this data structure.

## See also

[Extended Linguistic Services Structures](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-structures)

[MAPPING_PROPERTY_BAG](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_property_bag)