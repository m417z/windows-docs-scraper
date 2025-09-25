# PDEBUG_STACK_PROVIDER_ENDTHREADSTACKRECONSTRUCTION callback function

## Description

The *EndThreadStackReconstruction* callback function may be called after stack reconstruction to clean up state.

```cpp
 CALLBACK* PDEBUG_STACK_PROVIDER_ENDTHREADSTACKRECONSTRUCTION EndThreadStackReconstruction;
```

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*EndThreadStackReconstruction* is called **PDEBUG_STACK_PROVIDER_ENDTHREADSTACKRECONSTRUCTION** in the Dbgeng.h header file.