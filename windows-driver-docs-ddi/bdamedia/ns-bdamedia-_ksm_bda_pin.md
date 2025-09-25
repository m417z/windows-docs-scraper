# _KSM_BDA_PIN structure

## Description

The KSM_BDA_PIN structure describes a method request to create or delete a pin factory for a filter.

## Members

### `Method`

KSMETHOD structure that describes a method and request type of a method request.

### `PinId`

Member of the union in KSM_BDA_PIN that contains the identifier (ID) of a pin factory of a filter.

### `PinType`

Member of the union in KSM_BDA_PIN that contains the value that specifies the pin type.

### `Reserved`

Reserved.

## See also

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)