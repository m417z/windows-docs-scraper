## Description

**BLOCK_DEVICE_TOKEN_DESCRIPTOR** contains the token returned from the POPULATE TOKEN command for an offload read data operation. The token information is included as part of the [**RECEIVE_TOKEN_INFORMATION_RESPONSE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-receive_token_information_response_header) structure.

## Members

### `TokenIdentifier`

An identifier value assigned by the copy provider to provide uniqueness to **Token** while the value of **Token** is valid. This member is reserved for system use and must not be modified.

### `Token`

A data value defining a token as a point-in-time representation of data (ROD) for an offload read data operation. **Token** is an opaque value and must be used unmodified in offload write data operations.

## See also

[**RECEIVE_TOKEN_INFORMATION_RESPONSE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-receive_token_information_response_header)