# RPCOLEMESSAGE structure

## Description

Contains marshaling invocation arguments and return values between COM components.

## Members

### `reserved1`

This member is reserved.

### `dataRepresentation`

The data representation with which the data was marshaled.

### `Buffer`

A buffer for marshaled data.

### `cbBuffer`

The size of the buffer, in bytes.

### `iMethod`

The number of the method to be invoked.

### `reserved2`

This member is reserved.

### `rpcFlags`

Status flags for the RPC connection.

## See also

[IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer)

[IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer)