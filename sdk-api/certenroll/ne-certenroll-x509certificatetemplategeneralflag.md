# X509CertificateTemplateGeneralFlag enumeration

## Description

The **X509CertificateTemplateGeneralFlag** enumeration contains use and modification information about templates and associated certificates.

## Constants

### `GeneralMachineType:0x40`

The template should be used to create a certificate request for a computer.

### `GeneralCA:0x80`

The template should be used to create a request for a certification authority certificate.

### `GeneralCrossCA:0x800`

The template should be used to create a request to cross certify a certificate.

### `GeneralDefault:0x10000`

The template is not used by the client or server in the Windows Client Certificate Enrollment and should not be modified.

### `GeneralModified:0x20000`

The template is not used by the client or server in the Windows Client Certificate Enrollment and can be modified if necessary.

### `GeneralDonotPersist:0x1000`

The certification authority is not required to save a record of a certificate request for a certificate that has been issued.