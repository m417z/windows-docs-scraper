## Description

**RX_CONTENT_CREATE_FLAGS** specifies flags set by RDBSS and passed to operations sent to the network mini-redirector during the creation of a context.

## Constants

### `RX_CONTEXT_CREATE_FLAG_UNC_NAME:0x1`

The user presented a UNC path name.

### `RX_CONTEXT_CREATE_FLAG_STRIPPED_TRAILING_BACKSLASH:0x2`

The trailing backslash was stripped from the path name.

### `RX_CONTEXT_CREATE_FLAG_ADDEDBACKSLASH:0x4`

A backslash was added to the path name.

### `RX_CONTEXT_CREATE_FLAG_REPARSE:0x8`

A reparse operation is needed.

### `RX_CONTEXT_CREATE_FLAG_SPECIAL_PATH:0x10`

Designates the path as special.

## See also

[**RxCreateRxContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[**RX_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)