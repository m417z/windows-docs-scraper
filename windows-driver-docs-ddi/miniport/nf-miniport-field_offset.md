## Description

The **FIELD_OFFSET** macro returns the byte offset of a named field in a known structure type.

## Parameters

### `type`

Specifies the name of a known structure type containing **Field**.

### `field`

Specifies the name of a field in a structure of type **Type**.

## Remarks

Returns the byte offset of the caller supplied **Field** in the **Type** structure.

Used by device driver writers to symbolically determine the offset of a known field in a known structure type.

## See also

[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record)