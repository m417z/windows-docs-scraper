## Description

The **CONTAINING_RECORD** macro returns the base address of an instance of a structure given the type of the structure and the address of a field within the containing structure.

## Parameters

### `address`

[in]
A pointer to a field in an instance of a structure of type _Type_.

### `type`

[in]
The name of the type of the structure whose base address is to be returned.

### `field`

[in]
The name of the field pointed to by _Address_ and which is contained in a structure of type _Type_.

## Remarks

Returns a PCHAR containing the address of the base of the structure containing _Field_.

Called to determine the base address of a structure whose type is known when the caller has a pointer to a field inside such a structure. This macro is useful for symbolically accessing other fields in a structure of known type.