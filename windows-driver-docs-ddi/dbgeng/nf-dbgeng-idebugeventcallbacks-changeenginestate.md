# IDebugEventCallbacks::ChangeEngineState

## Description

The **ChangeEngineState** callback method is called by the engine when its state has changed.

## Parameters

### `Flags` [in]

Specifies a bit-set indicating the type of changes that occurred in the engine's state. The following bit flags might be set:

| Value | Description |
| --- | --- |
| DEBUG_CES_CURRENT_THREAD | The current thread has changed, which implies that the current target and current process might also have changed. |
| DEBUG_CES_EFFECTIVE_PROCESSOR | The effective processor has changed. |
| DEBUG_CES_BREAKPOINTS | One or more [breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/breakpoints3) have changed. |
| DEBUG_CES_CODE_LEVEL | The code interpretation level has changed. |
| DEBUG_CES_EXECUTION_STATUS | The execution status has changed. |
| DEBUG_CES_ENGINE_OPTIONS | The engine options have changed. |
| DEBUG_CES_LOG_FILE | The log file has been opened or closed. |
| DEBUG_CES_RADIX | The default radix has changed. |
| DEBUG_CES_EVENT_FILTERS | The event filters have changed. |
| DEBUG_CES_PROCESS_OPTIONS | The process options for the current process have changed. |
| DEBUG_CES_EXTENSIONS | Extension DLLs have been loaded or unloaded. (For more information, see [Loading Debugger Extension DLLs](https://learn.microsoft.com/windows-hardware/drivers/debugger/loading-debugger-extension-dlls).) |
| DEBUG_CES_SYSTEMS | A target has been added or removed. |
| DEBUG_CES_ASSEMBLY_OPTIONS | The assemble options have changed. |
| DEBUG_CES_EXPRESSION_SYNTAX | The default expression syntax has changed. |
| DEBUG_CES_TEXT_REPLACEMENTS | Text replacements have changed. |

### `Argument` [in]

Provides additional information about the change to the engine's state. If more than one bit flag is set in the *Flags* parameter, the *Argument* parameter is not used. Otherwise, the interpretation of the value of *Argument* depends on the value of *Flags*:

#### DEBUG_CES_CURRENT_THREAD

The value of *Argument* is the current engine thread ID or--if there is no current thread--DEBUG_ANY_ID. For more information, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).

#### DEBUG_CES_EFFECTIVE_PROCESSOR

The value of *Argument* is the type of the effective processor.

#### DEBUG_CES_BREAKPOINTS

The value of *Argument* is the breakpoint ID of the breakpoint that was changed or--if more than one breakpoint was changed--DEBUG_ANY_ID. For more information, see [Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/breakpoints3).

#### DEBUG_CES_CODE_LEVEL

The value of *Argument* is the code interpretation level.

#### DEBUG_CES_EXECUTION_STATUS

The value of *Argument* is the execution status (as described in the [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) topic) possibly combined with the bit flag DEBUG_STATUS_INSIDE_WAIT. DEBUG_STATUS_INSIDE_WAIT is set when a **WaitForEvent** call is pending. For more information, see [Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model).

#### DEBUG_CES_ENGINE_OPTIONS

The value of *Argument* is the engine options.

#### DEBUG_CES_LOG_FILE

The value of *Argument* is **TRUE** if the log file was opened and **FALSE** if the log file was closed.

#### DEBUG_CES_RADIX

The value of *Argument* is the default radix.

#### DEBUG_CES_EVENT_FILTERS

The value of *Argument* is the index of the event filter that was changed or--if more than one event filter was changed--DEBUG_ANY_ID.

#### DEBUG_CES_PROCESS_OPTIONS

The value of *Argument* is the process options for the current process.

#### DEBUG_CES_EXTENSIONS

The value of *Argument* is zero.

#### DEBUG_CES_SYSTEMS

The value of *Argument* is the target ID of the target that was added or--if a target was removed--DEBUG_ANY_ID.

#### DEBUG_CES_ASSEMBLE_OPTIONS

The value of *Argument* is the assemble options.

#### DEBUG_CES_EXPRESSION_SYNTAX

The value of *Argument* is the default expression syntax.

#### DEBUG_CES_TEXT_REPLACEMENTS

The value of *Argument* is DEBUG_ANY_ID.

## Return value

The return value is ignored by the engine unless it indicates a remote procedure call error; in this case the client, with which this **IDebugEventCallbacks** object is registered, is disabled.

## Remarks

This method is only called by the engine if the DEBUG_EVENT_CHANGE_ENGINE_STATE flag is set in the mask returned by [IDebugEventCallbacks::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-getinterestmask).

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).