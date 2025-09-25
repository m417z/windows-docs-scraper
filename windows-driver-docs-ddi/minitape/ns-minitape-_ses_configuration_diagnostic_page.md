# SES_CONFIGURATION_DIAGNOSTIC_PAGE structure (minitape.h)

## Description

The **SES_CONFIGURATION_DIAGNOSTIC_PAGE** structure provides enclosure descriptor information and parameters.

## Members

### `PageCode`

Specifies the diagnostic page being sent or requested based on the value. For a Microcode Control diagnostic page, the value should be 0x01.

### `NumberOfSecondarySubEnclosures`

Specifies the number of separate subenclosures included in
the enclosure descriptor list, not including the primary subenclosure. If this is set to zero, only the primary subenclosure exists.

### `PageLength`

Specifies the length of the diagnostic page, in bytes.

### `GenerationCode`

Specifies the value of the generation code.

### `Descriptors`

Specifies the enclosure descriptors for the primary and secondary enclosures. The primary enclosure is the first index.