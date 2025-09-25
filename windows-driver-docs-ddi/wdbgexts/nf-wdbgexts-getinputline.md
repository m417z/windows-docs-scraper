# GetInputLine function

## Description

The **GetInputLine** function requests an input string from the debugger.

## Parameters

### `Prompt`

Specifies a prompt to indicate what input is being requested. The prompt is printed to the debugger's output before the input is gathered. If *Prompt* is **NULL**, no prompt is printed.

### `Buffer`

Specifies the buffer to receive the input.

### `BufferSize`

Specifies the size, in characters, of the buffer *Buffer*.

## Return value

**GetInputLine** returns the size, in characters, of the input returned to the *Buffer* buffer, or zero, if no input was returned.