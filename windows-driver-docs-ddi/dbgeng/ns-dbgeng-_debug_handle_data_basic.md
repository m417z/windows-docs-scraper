# _DEBUG_HANDLE_DATA_BASIC structure

## Description

The DEBUG_HANDLE_DATA_BASIC structure contains handle-related information about a system object.

## Members

### `TypeNameSize`

The size, in characters, of the object-type name. This size includes the space for the '\0' terminating character.

### `ObjectNameSize`

The size, in characters, of the object's name. This size includes the space for the '\0' terminating character.

### `Attributes`

A bit-set that contains the handle's attributes. For possible values, see "Handle" in the Windows Driver Kit (WDK).

### `GrantedAccess`

A bit-set that specifies the access mask for the object that is represented by the handle. For details, see ACCESS_MASK in the Platform SDK documentation.

### `HandleCount`

The number of handle references for the object.

### `PointerCount`

The number of pointer references for the object.