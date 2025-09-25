## Description

This function is obsolete.

Checked builds were available on older versions of Windows, before Windows 10 version 1803. Use tools such as Driver Verifier and GFlags to check driver code in later versions of Windows.

## Parameters

### `DebugPrintLevel` [in]

Specifies an enumeration of type **STREAM_DEBUG_LEVEL**. The debugger prints messages if this parameter is less than or equal to the *StreamDebug* variable in *stream.sys* symbols.

### `DebugMessage` [in]

Points to a NULL-terminated string containing the message to print to the application window and to the Debugger Command window.

### `...`

Specifies a variable argument list containing optional arguments for the format string, as in **printf**.

## Remarks

## See also