# FhServiceClosePipe function

## Description

Closes a communication channel to the File History Service opened with [FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe).

> [!NOTE]
> **FhServiceClosePipe** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Pipe` [in]

The communication channel handle returned by an earlier [FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe) call.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

An application should call **FhServiceClosePipe** once for each communication channel handle it opens with [FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe). Closing a communication channel handle multiple times is not supported and may lead to unpredictable behavior.

## See also

[FhServiceOpenPipe](https://learn.microsoft.com/windows/desktop/api/fhsvcctl/nf-fhsvcctl-fhserviceopenpipe)