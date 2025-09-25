# IDebugEventCallbacks::ChangeSymbolState

## Description

The **ChangeSymbolState** callback method is called by the engine when the symbol state changes.

## Parameters

### `Flags` [in]

Specifies a bit-set indicating the nature of the change to the symbol state. The following bit flags might be set.

| Value | Description |
| --- | --- |
| DEBUG_CSS_LOADS | The engine has loaded some module symbols. |
| DEBUG_CSS_UNLOADS | The engine has unloaded some module symbols. |
| DEBUG_CSS_SCOPE | The current symbol scope has changed. |
| DEBUG_CSS_PATHS | The executable image, source , or symbol search paths have changed. |
| DEBUG_CSS_SYMBOL_OPTIONS | The symbol options have changed. |
| DEBUG_CSS_TYPE_OPTIONS | The type options have changed. |

### `Argument` [in]

Provides additional information about the change to the symbol state. If more than one bit flag is set in the *Flags* parameter, the *Argument* parameter is not used. Otherwise, the value of *Argument* depends on the value of *Flags*:

#### DEBUG_CSS_LOADS

The value of *Argument* is the base location (in the target's memory address space) of the module image that the engine loaded symbols for.

#### DEBUG_CSS_UNLOADS

The value of *Argument* is the base location (in the target's memory address space) of the module image that the engine unloaded symbols for. If the engine unloaded symbols for more than one image, the value of *Argument* is zero.

#### DEBUG_CSS_SCOPE

The value of *Argument* is zero.

#### DEBUG_CSS_PATHS

The value of *Argument* is zero.

#### DEBUG_CSS_SYMBOL_OPTIONS

The value of *Argument* is the symbol options.

#### DEBUG_CSS_TYPE_OPTIONS

The value of *Argument* is zero.

## Return value

The return value is ignored by the engine unless it indicates a remote procedure call error; in this case the client, with which this **IDebugEventCallbacks** object is registered, is disabled.

## Remarks

This method is only called by the engine if the DEBUG_EVENT_CHANGE_SYMBOL_STATE flag is set in the mask returned by [IDebugEventCallbacks::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-getinterestmask).

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).