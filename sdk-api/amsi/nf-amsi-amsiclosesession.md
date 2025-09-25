# AmsiCloseSession function

## Description

Close a session that was opened by [AmsiOpenSession](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiopensession).

## Parameters

### `amsiContext` [in]

The handle of type HAMSICONTEXT that was initially received from [AmsiInitialize](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiinitialize).

### `amsiSession` [in]

The handle of type HAMSISESSION that was initially received from [AmsiOpenSession](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiopensession).

## See also

[AmsiInitialize](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiinitialize)

[AmsiOpenSession](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiopensession)