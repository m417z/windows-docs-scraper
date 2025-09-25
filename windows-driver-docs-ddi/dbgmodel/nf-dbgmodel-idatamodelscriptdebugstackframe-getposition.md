# IDataModelScriptDebugStackFrame::GetPosition

## Description

The GetPosition method returns the position within the script represented by the stack frame. This method may only be called when the script is within a break represented by the stack in which this frame is contained. The line and column position within this frame is always returned. If the debugger is capable of returning the span of the "execution position" within the script, an ending position can be returned in the positionSpanEnd argument. If the debugger is not capable of this, the line and column values in the span end (if requested) should be set to zero.

The line of text (or the span of text) representing this frame can optionally be passed back by debuggers which support it. While it is strongly recommended that script debuggers make every attempt to return this text, there is no requirement that such debuggers return more than the line and column position of the frame. If return text is not supported, a nullptr can be returned in the lineText argument.

## Parameters

### `position`

The debugger should fill in the line and column positions of the frame in this argument.

### `positionSpanEnd`

The caller can optionally request the end of the span of text representing this stack frame by passing a non-nullptr value here. If the debugger can support such a request, it returns the line and column positions here; otherwise, the Line and Column fields of the data structure should be set to zero indicating that the values cannot be determined.

### `lineText`

The caller can optionally request the line of source code (or the span) representing the frame position. If the debugger is capable of returning this, it should return such here as a string allocated by the SysAllocString function. The caller is responsible for freeing the allocated string with SysFreeString. If the debugger is not capable of returning this, nullptr should be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugStackFrame interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe)