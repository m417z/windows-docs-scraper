# PDEBUG_STACK_PROVIDER_BEGINTHREADSTACKRECONSTRUCTION callback function

## Description

The *BeginThreadStackReconstruction* callback function causes debugger to pass the stream to the dump stack provider prior to thread enumeration.

```cpp
CALLBACK* PDEBUG_STACK_PROVIDER_BEGINTHREADSTACKRECONSTRUCTION BeginThreadStackReconstruction;
```

## Parameters

### `StreamType` [in]

A stream type.

### `MiniDumpStreamBuffer` [in]

A mini-dump stream buffer.

### `BufferSize` [in]

The size of the buffer.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*BeginThreadStackReconstruction* is called **PDEBUG_STACK_PROVIDER_BEGINTHREADSTACKRECONSTRUCTION** in the Dbgeng.h header file.