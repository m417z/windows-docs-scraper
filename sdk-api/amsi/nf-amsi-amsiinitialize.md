## Description

Initialize the AMSI API.

## Parameters

### `appName` [in]

The name, version, or GUID string of the app calling the AMSI API.

### `amsiContext` [out]

A handle of type HAMSICONTEXT that must be passed to all subsequent calls to the AMSI API.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the app is finished with the AMSI API it must call [AmsiUninitialize](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiuninitialize).

## See also

[AmsiUninitialize](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiuninitialize)