# AmsiOpenSession function

## Description

Opens a session within which multiple scan requests can be correlated.

## Parameters

### `amsiContext` [in]

The handle of type HAMSICONTEXT that was initially received from [AmsiInitialize](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiinitialize).

### `amsiSession` [out]

A handle of type HAMSISESSION that must be passed to all subsequent calls to the AMSI API within the session.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the app is finished with the session it must call [AmsiCloseSession](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiclosesession).

## See also

[AmsiCloseSession](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiclosesession)

[AmsiInitialize](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiinitialize)