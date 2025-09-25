## Description

**EATTRIBUTE_DATATYPE** enumerates the possible data types for a global attribute, feature attribute or option attribute.

## Constants

### `kADT_UNKNOWN`

The attribute is of unknown type.

### `kADT_BOOL`

The attribute is of type BOOL.

### `kADT_INT`

The attribute is of type INT.

### `kADT_LONG`

The attribute is of type LONG.

### `kADT_DWORD`

The attribute is of type DWORD.

### `kADT_ASCII`

The attribute is an ASCII string.

### `kADT_UNICODE`

The attribute is a Unicode string.

### `kADT_BINARY`

The attribute consists of binary data.

### `kADT_SIZE`

The attribute is of type SIZE.

### `kADT_RECT`

The attribute is of type RECT.

### `kADT_CUSTOMSIZEPARAMS`

The attribute is an array containing CUSTOMPARAM_MAX (a constant defined in printoem.h) elements. Each element is a [CUSTOMSIZEPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_customsizeparam) structure.

## See also

[CUSTOMSIZEPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_customsizeparam)