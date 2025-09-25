# CoRegisterActivationFilter function

## Description

Registers a process-wide filter to process activation requests.

## Parameters

### `pActivationFilter` [in]

Pointer to the filter to register.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This registers one and only one process-wide filter.