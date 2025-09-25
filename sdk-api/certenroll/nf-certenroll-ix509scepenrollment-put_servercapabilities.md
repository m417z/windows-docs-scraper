# IX509SCEPEnrollment::put_ServerCapabilities

## Description

Sets the preferred hash and encryption algorithms for the request.

This property is write-only.

## Parameters

## Remarks

If you do not set this property, then the default hash and encryption algorithms will be used.

This property must be set before calling the [CreateRequestMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-createrequestmessage), [CreateRetrievePendingMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-createretrievependingmessage), or [CreateRetrieveCertificateMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-createretrievecertificatemessage) methods.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)