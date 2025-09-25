# _MSR_SUPPORTED_CARD_TYPES structure

## Description

This structure defines the types of magnetic stripe cards supported by the reader.

## Members

### `Count`

Count of supported magnetic stripe cards defined in **CardTypes[MSR_CARD_TYPE_MAX_COUNT]**.

### `CardTypes`

Magnetic stripe cards supported by the reader. The first **Count** members are valid.