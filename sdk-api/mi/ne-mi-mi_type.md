# MI_Type enumeration

## Description

These
values specify the data type of qualifiers, properties, references,
parameters, and method return values for the CIM data types.

## Constants

### `MI_BOOLEAN:0`

unsigned char

### `MI_UINT8:1`

unsigned char

### `MI_SINT8:2`

signed char

### `MI_UINT16:3`

unsigned short

### `MI_SINT16:4`

signed short

### `MI_UINT32:5`

unsigned int

### `MI_SINT32:6`

signed int

### `MI_UINT64:7`

unsigned __int64

### `MI_SINT64:8`

signed __int64

### `MI_REAL32:9`

float

### `MI_REAL64:10`

double

### `MI_CHAR16:11`

unsigned short

### `MI_DATETIME:12`

Structure holding a union of [MI_Timestamp](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_timestamp) or [MI_Interval](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_interval).

### `MI_STRING:13`

MI_CHAR*

### `MI_REFERENCE:14`

This is encoded as an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance), but usually only the key properties are set.

### `MI_INSTANCE:15`

### `MI_BOOLEANA:16`

Array of **MI_BOOLEAN** types.

### `MI_UINT8A:17`

Array of **MI_UINT8** types.

### `MI_SINT8A:18`

Array of **MI_SINT8** types.

### `MI_UINT16A:19`

Array of **MI_UINT16** types.

### `MI_SINT16A:20`

Array of **MI_SINT16** types.

### `MI_UINT32A:21`

Array of **MI_UINT32** types.

### `MI_SINT32A:22`

Array of **MI_SINT32** types.

### `MI_UINT64A:23`

Array of **MI_UINT64** types.

### `MI_SINT64A:24`

Array of **MI_SINT64** types.

### `MI_REAL32A:25`

Array of **MI_REAL32** types.

### `MI_REAL64A:26`

Array of **MI_REAL64** types.

### `MI_CHAR16A:27`

Array of **MI_CHAR16** types.

### `MI_DATETIMEA:28`

Array of **MI_DATETIME** structures.

### `MI_STRINGA:29`

Array of **MI_STRING** types.

### `MI_REFERENCEA:30`

Array of **MI_REFERENCE** types.

### `MI_INSTANCEA:31`

Array of **MI_INSTANCE** types.

### `MI_ARRAY:16`

MI_ARRAY is not an actual type, rather this is the bit that signifies the type is an array.