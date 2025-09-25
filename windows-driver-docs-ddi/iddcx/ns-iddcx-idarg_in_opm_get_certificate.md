# IDARG_IN_OPM_GET_CERTIFICATE structure

## Description

 Gives information about the
OPM certificate.

## Members

### `CertificateType`

 [in] Type of certificate the information request is for.

### `CertificateBufferSizeInBytes`

 [in] Size of the buffer provided for the driver to copy the certificate to.

### `pCertificate`

 [out] A pointer to a buffer that the driver copies the certificate to.