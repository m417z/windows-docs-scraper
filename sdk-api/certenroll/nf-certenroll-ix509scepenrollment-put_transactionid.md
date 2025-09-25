# IX509SCEPEnrollment::put_TransactionId

## Description

Gets or sets the transaction id for the request.

This property is read/write.

## Parameters

## Remarks

If you do not specify a transaction id, then the [CreateRequestMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-createrequestmessage) method will create one. If the transaction id has not been set or the **CreateRequestMessage** method has not been called, then this property will return **CERTSRV_E_PROPERTY_EMPTY**.

After processing a pending request, the caller must save this value for later use when calling the [CreateRetrievePendingMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-createretrievependingmessage) method to format a message to be sent to the SCEP server to poll for the issued certificate.

Set this property before you call the [ProcessResponseMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-processresponsemessage) method when you are using a new instance of the [IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment) interface to install the response.

Set this property before you call the [CreateRetrievePendingMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-createretrievependingmessage) method when you are using a new instance of the [IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment) interface to create a retrieval message.

## See also

[IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment)