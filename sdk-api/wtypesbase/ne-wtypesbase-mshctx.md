# MSHCTX enumeration

## Description

Specifies the destination context, which is the process in which the unmarshaling is to be done.

## Constants

### `MSHCTX_LOCAL:0`

The unmarshaling process is local and has shared memory access with the marshaling process.

### `MSHCTX_NOSHAREDMEM:1`

The unmarshaling process does not have shared memory access with the marshaling process.

### `MSHCTX_DIFFERENTMACHINE:2`

The unmarshaling process is on a different computer. The marshaling code cannot assume that a particular piece of application code is installed on that computer.

### `MSHCTX_INPROC:3`

The unmarshaling will be done in another apartment in the same process.

### `MSHCTX_CROSSCTX:4`

Create a new context in the current apartment.

### `MSHCTX_RESERVED1`

## See also

[CoGetMarshalSizeMax](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmarshalsizemax)

[CoGetStandardMarshal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetstandardmarshal)

[CoMarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterface)

[IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)

[IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer)

[IStdMarshalInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istdmarshalinfo)