# CALLFRAMEPARAMINFO structure

## Description

Provides information about the parameter on the stack.

## Members

### `fIn`

**TRUE** if this is an [in] parameter; otherwise, **FALSE**.

### `fOut`

**TRUE** if this is an [out] parameter; otherwise, **FALSE**.

### `stackOffset`

Represents the offset in bytes from the stack location of the frame to the start of the parameter.

### `cbParam`

Represents the size in bytes occupied by the parameter on the stack.

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)