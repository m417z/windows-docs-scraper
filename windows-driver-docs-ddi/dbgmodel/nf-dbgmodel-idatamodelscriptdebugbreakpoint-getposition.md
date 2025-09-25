# IDataModelScriptDebugBreakpoint::GetPosition

## Description

The GetPosition method returns the position of the breakpoint within the script. The script debugger must return the line and column within source code where the breakpoint is located. If it is capable of doing so, it can also return a span of source represented by the breakpoint by filling out an end position as defined by the positionSpanEnd argument. If the debugger is not capable of producing this span and the caller requests it, the Line and Column fields of the span's ending position should be filled in as zero indicating that the values cannot be provided.

The debugger may also return the text of the line (or span) of source code where breakpoint exists in the lineText argument. While it is strongly recommended that debuggers return this value, it is not required. Only the line and column position within source are required return values. Should the debugger not be capable of producing the source text, nullptr may be returned in the lineText argument.

## Parameters

### `position`

The line and column position of the breakpoint within the script's source code must be returned here.

### `positionSpanEnd`

If the debugger is capable of producing the span of source represented by the breakpoint, it can return the line and column positions of the end of the span here. If not, the Line and Column values of the structure should be set to zero indicating that the values cannot be provided..

### `lineText`

If the debugger can produce the line (or span) of source code represented by the breakpoint, it returns such here as a string allocated via the SysAllocString function. The caller is responsible for freeing the returned string via SysFreeString. If the debugger is not capable of returning this source text, nullptr should be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugBreakpoint interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugbreakpoint)