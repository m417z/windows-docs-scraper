# PDEBUG_STACK_PROVIDER_RECONSTRUCTSTACK callback function

## Description

The *ReconstructStack* callback function queries dump stream provider on a per-thread basis.

```cpp
 CALLBACK* PDEBUG_STACK_PROVIDER_RECONSTRUCTSTACK ReconstructStack;
```

## Parameters

### `SystemThreadId` [in]

A system thread ID.

### `NativeFrames` [in]

Native frames.

### `CountNativeFrames` [in]

Specifies the number of native frames.

### `StackSymFrames` [out]

A pointer to a symbol frames stack.

### `StackSymFramesFilled` [out]

Symbol frames stack filled value.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function returns stack frames and symbolic data.

New in-line frames may be provided.

Stack dump provider must be enabled.

*ReconstructStack* is called **PDEBUG_STACK_PROVIDER_RECONSTRUCTSTACK** in the Dbgeng.h header file.