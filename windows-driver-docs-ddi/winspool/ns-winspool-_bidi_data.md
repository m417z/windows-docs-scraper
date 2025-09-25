# _BIDI_DATA structure

## Description

The BIDI_DATA structure is used to store the values of a bidi schema.

## Members

### `dwBidiType`

Specifies the type of data in a bidi request as one of the values listed in the [BIDI_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ne-winspool-bidi_type) enumeration. The value of this member determines which one of the following five union members is valid.

### `u`

### `u.bData`

Specifies the Boolean value. This member is valid only if the value of **dwBidiType** is BIDI_BOOL, one of the BIDI_TYPE enumerators.

### `u.iData`

Specifies the integer value. This member is valid only if the value of **dwBidiType** is BIDI_INT, one of the BIDI_TYPE enumerators.

### `u.sData`

Pointer to a memory location at which the first byte of the string is stored. This member is valid only if the value of **dwBidiType** is BIDI_STRING or BIDI_TEXT, two of the BIDI_TYPE enumerators.

### `u.fData`

Specifies the floating-point value. This member is valid only if the value of **dwBidiType** is BIDI_FLOAT, one of the BIDI_TYPE enumerators.

### `u.biData`

Specifies a [BINARY_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_binary_container) structure that holds the binary data. This member is valid only if the value of **dwBidiType** is BIDI_BLOB, one of the BIDI_TYPE enumerators.

## Remarks

The [BIDI_REQUEST_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_request_data) and [BIDI_RESPONSE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_data) structures each have a member of this type, which holds the bidi data for the request or response.

## See also

[BIDI_REQUEST_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_request_data)

[BIDI_RESPONSE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_data)

[BIDI_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ne-winspool-bidi_type)

[BINARY_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_binary_container)