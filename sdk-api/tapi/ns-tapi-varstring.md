# VARSTRING structure

## Description

The
**VARSTRING** structure is used for returning variably sized strings. It is used both by the line device class and the phone device class.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwStringFormat`

Format of the string. This member uses one of the
[STRINGFORMAT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/stringformat--constants).

### `dwStringSize`

Size of the string information, including the **null** terminator, in bytes.

### `dwStringOffset`

Offset from the beginning of the structure to the variably sized device field containing the string information. The size of the field is specified by **dwStringSize**.

## Remarks

No extensibility.

If a string cannot be returned in a variable structure, the **dwStringSize** and **dwStringOffset** members are set in one of the following ways:

* **dwStringSize** and **dwStringOffset** members are both set to zero.
* **dwStringOffset** is nonzero and **dwStringSize** is zero.
* **dwStringOffset** is nonzero, **dwStringSize** is 1, and the byte at the given offset is zero.