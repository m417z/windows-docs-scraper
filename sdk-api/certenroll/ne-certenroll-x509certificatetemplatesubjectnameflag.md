# X509CertificateTemplateSubjectNameFlag enumeration

## Description

The **X509CertificateTemplateSubjectNameFlag** enumeration contains values that specify server and client actions concerning subject names.

## Constants

### `SubjectNameEnrolleeSupplies:0x1`

Instructs the client to provide subject information in the certificate request.

### `SubjectNameRequireDirectoryPath:0x80000000`

Instructs the certification authority (CA) to specify the requestor's Active Directory distinguished name as the subject name in the issued certificate.

### `SubjectNameRequireCommonName:0x40000000`

Instructs the certification authority (CA) to specify the requestor's Active Directory common name (CN) as the subject name in the issued certificate.

### `SubjectNameRequireEmail:0x20000000`

Instructs the CA to specify the value of the **e-mail** attribute in the requestor's Active Directory user object as the subject name in the issued certificate.

### `SubjectNameRequireDNS:0x10000000`

Instructs the CA to specify the value of the **DNS** attribute in the requestor's Active Directory user object as the subject name in the issued certificate.

### `SubjectNameAndAlternativeNameOldCertSupplies:0x8`

Instructs the client to reuse the subject name and alternative subject name extensions from an existing valid certificate when creating a renewal certificate request. This flag can only be used when the **SubjectNameEnrolleeSupplies** or the **SubjectAlternativeNameEnrolleeSupplies** flag is specified.

### `SubjectAlternativeNameEnrolleeSupplies:0x10000`

Instructs the client to provide subject alternative name information in the certificate request.

### `SubjectAlternativeNameRequireDirectoryGUID:0x1000000`

Instructs the CA to add the value of the **objectGUID**  attribute in the requestor's Active Directory user object to the Subject Alternative Name extension in the issued certificate.

### `SubjectAlternativeNameRequireUPN:0x2000000`

Instructs the CA to add the value of the **UPN** attribute in the requestor's Active Directory user object to the Subject Alternative Name extension in the issued certificate.

### `SubjectAlternativeNameRequireEmail:0x4000000`

Instructs the CA to add the value of the **e-mail** attribute in the requestor's Active Directory user object to the Subject Alternative Name extension in the issued certificate.

### `SubjectAlternativeNameRequireSPN:0x800000`

Instructs the CA to add the value of the **SPN** attribute in the requestor's Active Directory user object to the Subject Alternative Name extension in the issued certificate.

### `SubjectAlternativeNameRequireDNS:0x8000000`

Instructs the CA to add the value of the **DNS** attribute in the requestor's Active Directory user object to the Subject Alternative Name extension in the issued certificate.

### `SubjectAlternativeNameRequireDomainDNS:0x400000`

Instructs the CA to add the value of the DNS of the root domain to the Subject Alternative Name extension in the issued certificate.