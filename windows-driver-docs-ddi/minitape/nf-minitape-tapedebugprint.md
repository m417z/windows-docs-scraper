# TapeDebugPrint function

## Description

The **TapeDebugPrint** routine prints the indicated string.

## Parameters

### `DebugPrintLevel`

Determines whether the string is printed. If **DebugPrintLevel** is less than or equal to the tape class global variable **TapeClassDebug**, **TapeDebugPrint** prints the debug message, otherwise nothing is printed. If this parameter has a value of zero, **TapeClassDebug** always prints the message.

### `DebugMessage`

Pointer to the string to be printed.

### `...`

Variadic arguments for the string that **DebugMessage** points to.

## Return value

None