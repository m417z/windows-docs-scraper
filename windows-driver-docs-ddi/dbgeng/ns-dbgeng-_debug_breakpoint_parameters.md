# _DEBUG_BREAKPOINT_PARAMETERS structure

## Description

The DEBUG_BREAKPOINT_PARAMETERS structure contains most of the parameters for describing a breakpoint.

## Members

### `Offset`

The location in the target's memory address space that will trigger the breakpoint. If the breakpoint is deferred (see [GetFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getflags)), **Offset** is DEBUG_INVALID_OFFSET. See [GetOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getoffset).

### `Id`

The breakpoint ID. See [GetId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getid).

### `BreakType`

Specifies if the breakpoint is a software breakpoint or a processor breakpoint. See [GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-gettype).

### `ProcType`

The processor type for which the breakpoint is set. See [GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-gettype).

### `Flags`

The flags for the breakpoint. See [GetFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getflags).

### `DataSize`

The size, in bytes, of the memory block whose access will trigger the breakpoint. If the type of the breakpoint is not a data breakpoint, this is zero. See [GetDataParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getdataparameters).

### `DataAccessType`

The type of access that will trigger the breakpoint. If the type of the breakpoint is not a data breakpoint, this is zero. See [GetDataParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getdataparameters).

### `PassCount`

The number of times the target will hit the breakpoint before it is triggered. See [GetPassCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getpasscount).

### `CurrentPassCount`

The remaining number of times that the target will hit the breakpoint before it is triggered. See [GetCurrentPassCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getcurrentpasscount).

### `MatchThread`

The engine thread ID of the thread that can trigger this breakpoint. If any thread can trigger this breakpoint, **MatchThread** is DEBUG_ANY_ID. See [GetMatchThreadId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getmatchthreadid).

### `CommandSize`

The size, in characters, of the command string that will be executed when the breakpoint is triggered. If no command is set, **CommandSize** is zero. See [GetCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getcommand).

### `OffsetExpressionSize`

The size, in characters, of the expression string that evaluates to the location in the target's memory address space where the breakpoint is triggered. If no expression string is set, **OffsetExpressionSize** is zero. See [GetOffsetExpression](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getoffsetexpression).

## Remarks

For an overview of how to use breakpoints, and a description of all breakpoint-related methods, see [Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/breakpoints3).