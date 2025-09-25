## Description

A token, created as a representation of data (ROD), for an offload read data operation is returned in a **RECEIVE_TOKEN_INFORMATION_RESPONSE_HEADER** structure.

## Members

### `TokenDescriptorsLength`

The length, in bytes, of the **TokenDescriptor** member.

### `TokenDescriptor`

The data containing a token created as the offload read ROD.

## Remarks

The **RECEIVE_TOKEN_INFORMATION_RESPONSE_HEADER** structure is included with a [**RECEIVE_TOKEN_INFORMATION_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-receive_token_information_header)structure as a response to a POPULATE TOKEN command. The **RECEIVE_TOKEN_INFORMATION_RESPONSE_HEADER** structure follows the **SenseData** member of **RECEIVE_TOKEN_INFORMATION_HEADER**.

All multibyte values are in big endian format. Prior to evaluation, these values must be converted to match the endian format of the current platform.

## See also

[**POPULATE_TOKEN_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header)

[**RECEIVE_TOKEN_INFORMATION_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-receive_token_information_header)