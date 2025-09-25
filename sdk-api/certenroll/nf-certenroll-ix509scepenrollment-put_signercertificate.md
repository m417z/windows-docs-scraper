# IX509SCEPEnrollment::put_SignerCertificate

## Description

Gets or sets the signer certificate for the request.

This property is read/write.

## Parameters

## Remarks

To create a renewal request, you must set this property prior to calling the [CreateRequestMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-createrequestmessage) method. Otherwise, the **CreateRequestMessage** method will create a new request and generate a self-signed certificate using the same private key as the inner PKCSV10 reqeust.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)