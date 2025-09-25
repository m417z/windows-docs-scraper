# PWINDBG_GET_THREAD_CONTEXT_ROUTINE callback function

## Description

The **PWINDBG_GET_THREAD_CONTEXT_ROUTINE** (**GetContext**) function implements the functionality that is similar to the Microsoft Win32 **GetThreadContext** routine. It returns the context of the process being debugged.

## Parameters

### `Processor`

Specifies the index of the processor.

### `lpContext` [out]

Points to the address of a context structure that receives the appropriate context of the process being debugged. The context structure is highly machine-specific.

### `cbSizeOfContext` [in]

Specifies the size of the context structure.

## Return value

If the routine succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.