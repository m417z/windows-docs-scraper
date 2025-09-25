# FIELD_OFFSET macro

## Description

The **FIELD_OFFSET** macro returns the byte offset of a named field in a known structure type.

## Parameters

### `type` [in]

Specifies the name of a known structure type containing *Field*.

### `field` [in]

Specifies the name of a field in a structure of type *Type*.

## Remarks

Used by device driver writers to symbolically determine the offset of a known field in a known structure type.

## See also

[CONTAINING_RECORD](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer)