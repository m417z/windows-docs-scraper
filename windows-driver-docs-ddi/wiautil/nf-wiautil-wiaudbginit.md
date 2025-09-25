# wiauDbgInit macro

## Description

The **wiauDbgInit** function initializes WIA debugging.

## Parameters

### `a`

- **hInstance [in, optional]** - Is the handle to the DLL instance.

## Remarks

If the **wiauDbgInit** function not called, all DLLs loaded by a process inherit the debug flags of that process.