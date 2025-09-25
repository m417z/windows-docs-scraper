# _KSM_PIN structure

## Description

The KSM_PIN structure describes a method request to create or delete a pin factory for a filter.

## Members

### `Method`

KSMETHOD structure that describes a method and request type of a method request.

### `PinId`

Member of the union in KSM_PIN that contains the identifier (ID) of a pin factory of a filter.

### `PinType`

Member of the union in KSM_PIN that contains the value that specifies the pin type.

### `Reserved`

Reserved.

## Remarks

When the network provider creates or deletes a pin for a filter using either KSMETHOD_BDA_CREATE_PIN_FACTORY or KSMETHOD_BDA_DELETE_PIN_FACTORY of the KSMETHODSETID_BdaDeviceConfiguration method set, the BDA minidriver for the filter gives that pin an ID. The ID for the pin is returned in KSM_PIN.

## See also

[KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)