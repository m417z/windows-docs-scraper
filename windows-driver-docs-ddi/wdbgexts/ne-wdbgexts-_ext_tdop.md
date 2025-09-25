# _EXT_TDOP enumeration

## Description

The EXT_TDOP enumeration is used in the **Operation** member of the [EXT_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_ext_typed_data) structure to specify which suboperation the [DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi)
 [Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request) operation will perform.

## Constants

### `EXT_TDOP_COPY`

Makes a copy of a typed data description.

### `EXT_TDOP_RELEASE`

Releases a typed data description.

### `EXT_TDOP_SET_FROM_EXPR`

Returns the value of an expression.

### `EXT_TDOP_SET_FROM_U64_EXPR`

Returns the value of an expression. An optional address can be provided as a parameter to the expression.

### `EXT_TDOP_GET_FIELD`

Returns a member of a structure.

### `EXT_TDOP_EVALUATE`

Returns the value of an expression. An optional value can be provided as a parameter to the expression.

### `EXT_TDOP_GET_TYPE_NAME`

Returns the type name for typed data.

### `EXT_TDOP_OUTPUT_TYPE_NAME`

Prints the type name for typed data.

### `EXT_TDOP_OUTPUT_SIMPLE_VALUE`

Prints the value of typed data.

### `EXT_TDOP_OUTPUT_FULL_VALUE`

Prints the type and value for typed data.

### `EXT_TDOP_HAS_FIELD`

Determines whether a structure contains a specified member.

### `EXT_TDOP_GET_FIELD_OFFSET`

Returns the offset of a member within a structure.

### `EXT_TDOP_GET_ARRAY_ELEMENT`

Returns an element from an array.

### `EXT_TDOP_GET_DEREFERENCE`

Dereferences a pointer, returning the value it points to.

### `EXT_TDOP_GET_TYPE_SIZE`

Returns the size of the specified typed data.

### `EXT_TDOP_OUTPUT_TYPE_DEFINITION`

Prints the definition of the type for the specified typed data.

### `EXT_TDOP_GET_POINTER_TO`

Returns a new typed data description that represents a pointer to specified typed data.

### `EXT_TDOP_SET_FROM_TYPE_ID_AND_U64`

Creates a typed data description from a type and memory location.

### `EXT_TDOP_SET_PTR_FROM_TYPE_ID_AND_U64`

Creates a typed data description representing a pointer to a specified memory location with specified type.

### `EXT_TDOP_COUNT`

Does not specify an operation. Instead, it represents the number of suboperations defined in the EXT_TDOP enumeration.

## See also

[DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi)

[EXT_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_ext_typed_data)

[Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request)