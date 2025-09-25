# IDataModelScriptDebug::GetCurrentPosition

## Description

The GetCurrentPosition' method returns the current position within the script. This may only be called when the script is broken into the debugger where a call to GetScriptState would return ScriptDebugBreak. Any other call to this method is invalid and will fail.

The position of the script is defined as a span of characters. The start of the span must always be returned (both the line and column numbers). If the particular debugger is capable of returning the full span of the "current position" within the script, an ending position can optionally be returned in the positionSpanEnd argument. If the debugger is not capable of this, the line and column values in the span end (if requested) should be set to zero.

If the debugger can pass the source code for the line of code where the debugger is broken, it may return such from this method. If possible, it is strongly encouraged to provide this information. There is, however, no requirement that any more information than the starting line and column of the break position is returned. If source line information is not supported, a nullptr value may be returned for that argument.

## Parameters

### `currentPosition`

The current break position of the script must be returned here. The Line and Column fields of the returned structure are one based. A zero value in either indicates that the information is unavailable.

### `positionSpanEnd`

If the debugger is capable of determining the full span of the break position, the ending position of the span can be returned here. If not, zero values should be filled into the Line and Column fields of the returned structure.

### `lineText`

If the debugger is capable of returning the source code for the line (or the span) of the break, such can be returned here as a string allocated by the SysAllocString function. The caller is responsible for freeing the returned string with SysFreeString. If the debugger is incapable of producing this source information, nullptr should be returned.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebug interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug)