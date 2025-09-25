# IF_COUNTED_STRING_LH structure

## Description

The **IF_COUNTED_STRING** structure specifies a counted string for NDIS interfaces.

## Members

### `Length`

A USHORT value that contains the length, in bytes, of the string.

### `String`

A WCHAR buffer that contains the string. The string does not need to be null-terminated.

## Remarks

The **IF_COUNTED_STRING** structure is the data type for various NDIS string structures, such as **NDIS_IF_COUNTED_STRING**.

If the string is NULL-terminated, the **Length** member must not include the terminating NULL character.