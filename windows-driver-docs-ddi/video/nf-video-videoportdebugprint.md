# VideoPortDebugPrint function

## Description

Video miniport drivers should not call the **VideoPortDebugPrint** function. Instead, they should call the [VideoDebugPrint](https://learn.microsoft.com/previous-versions/ff570170(v=vs.85)) macro.

## Parameters

### `DebugPrintLevel`

### `DebugMessage` [in]

Pointer to a string that contains the debug message.

### `...`

Additional Parameters.

## Return value

None