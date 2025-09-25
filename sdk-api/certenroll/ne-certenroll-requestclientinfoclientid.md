# RequestClientInfoClientId enumeration

## Description

The **RequestClientInfoClientId** enumeration specifies the type of application that created a [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This can be used to initialize a [IX509AttributeClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeclientid) object that contains information about the client. It is also used by the [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) interface.

## Constants

### `ClientIdNone:0`

No client identifier is specified.

### `ClientIdXEnroll2003:1`

Specifies the Certificate Enrollment Control that is available on Windows Server 2003.

### `ClientIdAutoEnroll2003:2`

Specifies the autoenrollment that is available on Windows Server 2003.

### `ClientIdWizard2003:3`

Specifies the Certificate Request Wizard that is available on Windows Server 2003.

### `ClientIdCertReq2003:4`

Specifies the Certreq.exe command-line tool that is available on Windows Server 2003.

### `ClientIdDefaultRequest:5`

Specifies the default certificate request object that is available starting with Windows Vista. This is represented by the [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) interface and is the default value if the client ID is not set by the caller.

### `ClientIdAutoEnroll:6`

Specifies the autoenrollment that is available starting with Windows Vista.

### `ClientIdRequestWizard:7`

Specifies the Certificate Request Wizard that is available starting with Windows Vista.

### `ClientIdEOBO:8`

Specifies the Enroll-On-Behalf-Of (EOBO) Wizard that is available starting with Windows Vista.

### `ClientIdCertReq:9`

Specifies the Certreq.exe command-line tool that is available starting with Windows Vista.

### `ClientIdTest:10`

This value is not supported.

### `ClientIdWinRT:11`

### `ClientIdUserStart:1000`

This is the base value for custom applications.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509AttributeClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeclientid)

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)