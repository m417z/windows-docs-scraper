# wiasCreateLogInstance function

## Description

The **wiasCreateLogInstance** function creates an instance of a logging object.

## Parameters

### `pModuleHandle` [in]

Pointer to the module handle, which is used to filter output.

### `ppIWiaLogEx` [out]

Pointer to a memory location that receives the address of the logging interface.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).