# ICEnroll4::addBlobPropertyToCertificate

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addBlobPropertyToCertificate** method adds a [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) property to a certificate.

This property was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `lPropertyId` [in]

The identifier of the [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) property to add to the certificate.

### `lReserved` [in]

This parameter is reserved and must be zero.

### `bstrProperty` [in]

The data associated with the BLOB property. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_PVK_FILE_PROP_ID** | The name of the file that contains the private key associated with the certificate's public key. |
| **CERT_FRIENDLY_NAME_PROP_ID** | The display name for the certificate. |
| **CERT_DESCRIPTION_PROP_ID** | The property displayed by the certificate UI. This property allows the user to describe the certificate's use. |
| **CERT_RENEWAL_PROP_ID** | The hash of the renewed certificate. |

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)