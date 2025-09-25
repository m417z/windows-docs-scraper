## Description

Provides information about the context in which marshalling should be carried out.

## Members

### `fIn`

**TRUE** if the in parameter values are to be marshaled and **FALSE** if the out parameter values are to be marshaled. The in parameter values are marshaled on the client side and the out parameter values are marshaled on the server side.

### `dwDestContext`

Context in which unmarshaling is to be carried out.

### `pvDestContext`

Context in which unmarshaling is to be carried out.

### `punkReserved`

This parameter should be **NULL**.

### `guidTransferSyntax`

The transfer syntax for which the marshalling should occur.

## See also

[CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx)

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)

[ICallUnmarshal](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallunmarshal)