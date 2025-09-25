# X509SCEPDisposition enumeration

## Description

The **X509SCEPDisposition** enumeration describes the resulting disposition of a request to process a response message. This enumeration is used by the [IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment) interface.

## Constants

### `SCEPDispositionUnknown:-1`

### `SCEPDispositionSuccess:0`

The request was successful.

### `SCEPDispositionFailure:2`

The request failed.

### `SCEPDispositionPending:3`

The request has not completed yet.

### `SCEPDispositionPendingChallenge:11`

## See also

[ProcessResponseMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-processresponsemessage)