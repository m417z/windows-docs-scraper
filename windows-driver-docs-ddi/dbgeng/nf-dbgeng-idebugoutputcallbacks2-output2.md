# IDebugOutputCallbacks2::Output2

## Description

Returns notifications for the [IDebugOutputCallbacks2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks2) interface.

## Parameters

### `Which` [in]

The kind of DEBUG_OUTCB_XXX notification that is coming in. The DEBUG_OUTCB_XXX notifications are defined in the dbgeng.h header using #defines. For more information, see [DEBUG_OUTCB_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outcb-xxx).

### `Flags` [in]

Flags that are part of the notification payload.

### `Arg` [in]

Arguments that are part of the notification payload.

### `Text` [in, optional]

A pointer to text that is part of the notification payload.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDebugOutputCallbacks2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks2)