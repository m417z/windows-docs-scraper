# wiauGetDrvItemContext function

## Description

The **wiauGetDrvItemContext** function gets the driver item context, and optionally, the driver item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `ppItemCtx` [in, out]

Pointer to a memory location that receives a pointer to the driver item context.

### `ppDrvItem` [in, out]

*Optional*. Pointer to a memory location that receives a pointer to a driver item. The default value of this parameter is **NULL**, which means that when this function returns, no change is made to this parameter.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.