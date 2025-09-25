# tagPOINTER_INPUT_TYPE enumeration

## Description

Identifies the pointer input types.

## Constants

### `PT_POINTER:1`

Generic pointer type. This type never appears in pointer messages or pointer data. Some data query functions allow the caller to restrict the query to specific pointer type. The **PT_POINTER** type can be used in these functions to specify that the query is to include pointers of all types

### `PT_TOUCH:2`

Touch pointer type.

### `PT_PEN:3`

Pen pointer type.

### `PT_MOUSE:4`

Mouse pointer type.

### `PT_TOUCHPAD:5`

Touchpad pointer type (Windows 8.1 and later).

## See also

[Enumerations](https://learn.microsoft.com/windows/win32/inputmsg/enums)