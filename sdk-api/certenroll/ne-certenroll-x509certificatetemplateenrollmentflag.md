# X509CertificateTemplateEnrollmentFlag enumeration

## Description

The **X509CertificateTemplateEnrollmentFlag** enumeration contains values that specify server and client actions during enrollment.

## Constants

### `EnrollmentIncludeSymmetricAlgorithms:0x1`

Instructs the client and server to include a Secure/Multipurpose Internet Mail Extensions (S/MIME) extension in the certificate request and issued certificate.

### `EnrollmentPendAllRequests:0x2`

Instructs the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) to place all certificate requests in a pending state.

### `EnrollmentPublishToKRAContainer:0x4`

Instructs the certification authority to publish the issued certificate to the key recovery agent (KRA) container in Active Directory.

### `EnrollmentPublishToDS:0x8`

Instructs clients and servers to append the issued certificate to the **userCertificate** attribute on the user object in Active Directory.

### `EnrollmentAutoEnrollmentCheckUserDSCertificate:0x10`

Instructs clients to not automatically enroll a certificate based on this template if the **userCertificate** attribute on the user object in Active Directory already contains a valid certificate based on this template.

### `EnrollmentAutoEnrollment:0x20`

Instructs clients to automatically enroll a certificate that is based on this template.

### `EnrollmentDomainAuthenticationNotRequired:0x80`

Not used.

### `EnrollmentPreviousApprovalValidateReenrollment:0x40`

Instructs clients to sign a certificate by using private keys whose public keys are contained in existing certificates.

### `EnrollmentUserInteractionRequired:0x100`

Instructs the client to obtain user consent before attempting to enroll a certificate request based on this template.

### `EnrollmentAddTemplateName:0x200`

Not used.

### `EnrollmentRemoveInvalidCertificateFromPersonalStore:0x400`

Instructs the client to delete expired, revoked, or renewed certificates from the local certificate store.

### `EnrollmentAllowEnrollOnBehalfOf:0x800`

Instructs the server to allow enroll-on-behalf-of (EOBO) functionality.

### `EnrollmentAddOCSPNoCheck:0x1000`

Instructs the server to not include revocation information in the issued certificate, adding instead an id-pkix-ocsp-nocheck extension that specifies that the certificate holder can be trusted for the life of the certificate.

### `EnrollmentReuseKeyOnFullSmartCard:0x2000`

Instructs the client to reuse a private key for a smart card based certificate renewal if a new private key cannot be created on the card.

### `EnrollmentNoRevocationInfoInCerts:0x4000`

Instructs the server to not include revocation information in the issued certificate.

### `EnrollmentIncludeBasicConstraintsForEECerts:0x8000`

Instructs the server to include the Basic Constraints extension in the issued certificate.

### `EnrollmentPreviousApprovalKeyBasedValidateReenrollment:0x10000`

### `EnrollmentCertificateIssuancePoliciesFromRequest:0x20000`

### `EnrollmentSkipAutoRenewal:0x40000`