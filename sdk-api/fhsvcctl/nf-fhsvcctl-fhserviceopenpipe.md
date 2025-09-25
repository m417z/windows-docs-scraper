# FhServiceOpenPipe function

## Description

Opens a communication channel to the File History Service.

> [!NOTE]
> **FhServiceOpenPipe** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `StartServiceIfStopped` [in]

If the File History Service is not started yet and this parameter is **TRUE**, this function starts the File History Service before opening a communication channel to it.

If the File History Service is not started yet and this parameter is **FALSE**, this function fails and returns an unsuccessful **HRESULT** value.

### `Pipe` [out]

On successful return, this parameter contains a non-NULL handle representing a newly opened communication channel to the File History Service.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## See also

[FhServiceClosePipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceclosepipe)