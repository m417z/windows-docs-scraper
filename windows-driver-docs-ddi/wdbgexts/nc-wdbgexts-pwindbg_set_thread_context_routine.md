# PWINDBG_SET_THREAD_CONTEXT_ROUTINE callback function

## Description

The **PWINDBG_SET_THREAD_CONTEXT_ROUTINE** (**SetContext**) function is similar to the Win32 **SetThreadContext** routine. It sets the context of the process being debugged.

## Parameters

### `Processor`

The processor.

### `lpContext` [out]

Points to the address of a context structure that contains the context to be set for the process being debugged. The context structure is highly machine-specific.

### `cbSizeOfContext` [in]

Specifies the size of the context structure.

## Return value

If the routine succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.