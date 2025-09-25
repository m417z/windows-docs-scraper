# MAPPING_PROPERTY_BAG structure

## Description

Contains the text recognition data properties retrieved by [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext).

## Members

### `Size`

Size of the structure, used to verify the structure version. This value is required.

### `prgResultRanges`

Pointer to an array of [MAPPING_DATA_RANGE](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_data_range) structures containing all recognized text range results. This member is populated by [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext).

### `dwRangesCount`

Number of items in the array indicated by **prgResultRanges**. This member is populated by [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext).

### `pServiceData`

Pointer to private service data. The service can document the format of this data so that the application can use it. The service also manages the memory for this data. This member is populated by [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext).

### `dwServiceDataSize`

Size, in bytes, of the private service data specified by **pServiceData**. The size is set to 0 if there is no private data. This member is populated by [MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext).

### `pCallerData`

Pointer to private application data to pass to the service. The application manages the memory for this data.

### `dwCallerDataSize`

Size, in bytes, of the private application data indicated in **pCallerData**. This member is set to 0 if there is no private data.

### `pContext`

Reserved for internal use.

## Remarks

The memory for the property bag structure itself is managed by the application. The ELS platform and its services only manage the data pointers that they store in the property bag.

## See also

[Extended Linguistic Services Structures](https://learn.microsoft.com/windows/desktop/Intl/extended-linguistic-services-structures)

[MAPPING_DATA_RANGE](https://learn.microsoft.com/windows/desktop/api/elscore/ns-elscore-mapping_data_range)

[MappingRecognizeText](https://learn.microsoft.com/windows/desktop/api/elscore/nf-elscore-mappingrecognizetext)