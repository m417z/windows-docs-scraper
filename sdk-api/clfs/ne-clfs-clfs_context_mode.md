# CLFS_CONTEXT_MODE enumeration

## Description

Specifies a context mode type that indicates the direction and access methods that a client uses to scan a log. The context mode is set by using [ReadLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrecord), and is embedded in the read context that these two functions return.

## Constants

### `ClfsContextNone:0x00`

Do not move the cursor.

### `ClfsContextUndoNext`

Move the cursor backward to the next undo record.

### `ClfsContextPrevious`

Move the cursor to the previous log record from the current read context.

### `ClfsContextForward`

Move the cursor to the next client log record from the current read context.

## See also

[ReadLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrecord)