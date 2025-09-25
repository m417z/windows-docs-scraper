# IEnroll4::addBlobPropertyToCertificateWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addBlobPropertyToCertificateWStr** method adds a [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) property to a certificate. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `lPropertyId` [in]

The identifier of the BLOB property to add to the certificate.

### `lReserved` [in]

This parameter is reserved. Must be zero.

### `pBlobProperty` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the data for the BLOB property.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)