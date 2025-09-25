# PDEBUG_STACK_PROVIDER_FREESTACKSYMFRAMES callback function

## Description

The *FreeStackSymFrames* callback function frees memory from a stack provider.

```cpp
 CALLBACK* PDEBUG_STACK_PROVIDER_FREESTACKSYMFRAMES FreeStackSymFrames;
```

## Parameters

### `StackSymFrames` [in, optional]

A stack to free.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After *FreeStackSymFrames* is called, the debugger calls the stack provider to free memory.

*FreeStackSymFrames* is called **PDEBUG_STACK_PROVIDER_FREESTACKSYMFRAMES** in the Dbgeng.h header file.

## See also

[EndThreadStackReconstruction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_stack_provider_endthreadstackreconstruction)