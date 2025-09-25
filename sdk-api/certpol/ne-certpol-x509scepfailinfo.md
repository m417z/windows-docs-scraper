# X509SCEPFailInfo enumeration

## Description

The **X509SCEPFailInfo** enumeration describes the nature of an SCEP certificate enrollment failure. This enumeration is used by the [IX509SCEPEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509scepenrollment) interface.

## Constants

### `SCEPFailUnknown:-1`

### `SCEPFailBadAlgorithm:0`

Failure due to an unrecognized or unsupported algorithm.

### `SCEPFailBadMessageCheck:1`

The integrity check failed.

### `SCEPFailBadRequest:2`

The transaction was not permitted or was not supported.

### `SCEPFailBadTime:3`

The signing time attribute from the PKCS7 authenticated attributes was not sufficiently close to the system time.

### `SCEPFailBadCertId:4`

No certificate could be identified.

## See also

[FailInfo](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509scepenrollment-get_failinfo)