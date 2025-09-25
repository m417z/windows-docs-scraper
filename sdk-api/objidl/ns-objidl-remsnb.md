# RemSNB structure

## Description

The
**RemSNB** structure is used for marshaling the
[SNB](https://learn.microsoft.com/windows/desktop/Stg/snb) data type.

Defined in the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface (Storag.idl).

## Members

### `ulCntStr`

Number of strings in the **rgString** buffer.

### `ulCntChar`

Size in bytes of the **rgString** buffer.

### `rgString`

Pointer to an array of bytes containing the stream name strings from the **SNB** structure.

## See also

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)