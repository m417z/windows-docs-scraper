# AmsiScanString function

## Description

Scans a string for malware.

## Parameters

### `amsiContext` [in]

The handle of type HAMSICONTEXT that was initially received from [AmsiInitialize](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiinitialize).

### `string` [in]

The string to be scanned.

### `contentName` [in]

The filename, URL, unique script ID, or similar of the content being scanned.

### `amsiSession` [in, optional]

If multiple scan requests are to be correlated within a session, set *session* to the handle of type HAMSISESSION that was initially received from [AmsiOpenSession](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiopensession). Otherwise, set *session* to **nullptr**.

### `result` [out]

The result of the scan. See [AMSI_RESULT](https://learn.microsoft.com/windows/desktop/api/amsi/ne-amsi-amsi_result).

An app should use [AmsiResultIsMalware](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiresultismalware) to determine whether the content should be blocked.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[AMSI_RESULT](https://learn.microsoft.com/windows/desktop/api/amsi/ne-amsi-amsi_result)

[AmsiInitialize](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiinitialize)

[AmsiOpenSession](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiopensession)

[AmsiResultIsMalware](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiresultismalware)