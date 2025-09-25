# IX509SCEPEnrollment::CreateRequestMessage

## Description

Create a PKCS10 request message with a challenge password. The request message is in an enveloped PKCS7 encrypted with the SCEP server encryption certificate and signed by the server signing certificate.

## Parameters

### `Encoding` [in]

### `pValue` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-initialize) method before calling this method.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)