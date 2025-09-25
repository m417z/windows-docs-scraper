# EnrollmentCAProperty enumeration

## Description

The **EnrollmentCAProperty** enumeration specifies certification authority property values. It is used by the [Property](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertificationauthority-get_property) method on the [ICertificationAuthority](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificationauthority) interface.

## Constants

### `CAPropCommonName:1`

A **VT_BSTR** value that contains the common name of the certification authority (CA) in Active Directory.

### `CAPropDistinguishedName:2`

A **VT_DISPATCH** value that contains a pointer to an [IX500DistinguishedName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix500distinguishedname) object.

### `CAPropSanitizedName:3`

A **VT_BSTR** value that contains the sanitized common name of the CA in Active Directory. A name is sanitized by replacing disallowed characters with an exclamation point (!) followed by four hexadecimal values that represent the character.

### `CAPropSanitizedShortName:4`

A **VT_BSTR** value that contains the sanitized and shortened common name of the CA in Active Directory. A name is sanitized by replacing disallowed characters with an exclamation point (!) followed by four hexadecimal values that represent the character. The name is then shortened so that it does not exceed 51 characters. The characters that are removed from the sanitized string must be hashed and the hash converted to a 5-character string.

### `CAPropDNSName:5`

A **VT_BSTR** value that contains the DNS name of the CA in Active Directory.

### `CAPropCertificateTypes:6`

A **VT_ARRAY|VT_BSTR** collection of templates supported by the CA.

### `CAPropCertificate:7`

A **VT_ARRAY | VT_UI1** value that contains the signing certificate used by the CA.

### `CAPropDescription:8`

A **VT_BSTR** value that contains a description comment for the CA.

### `CAPropWebServers:9`

A **VT_ARRAY|VT_BSTR** collection of certificate enrollment servers configured for the CA. Each string in the collection contains a server URL, the authentication method used, an integer that specifies the priority level, and an integer that specifies whether the server can perform only certificate renewals. Each value is delimited by a newline character.

### `CAPropSiteName:10`

A **VT_BSTR** value that contains the name of the AD site to which the CA belongs. This can be used by the enrolling clients to determine the relative cost of communicating with the CA versus CAs that belong to other sites. This value is relevant only for CA objects retrieved by using the [GetCAs](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-getcas) method on the [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) interface.

### `CAPropSecurity:11`

A **VT_BSTR** value that contains the security descriptor definition language (SDDL) string representation of the security descriptor for the CA. This value is relevant only for CA objects retrieved by using the [GetCAs](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-getcas) method.

### `CAPropRenewalOnly:12`

A **VT_BOOL** value that specifies whether a CA is configured to perform only certificate renewals. This value is relevant only for CA objects retrieved by using the [GetCAs](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-getcas) method.

## See also

[ICertificationAuthority](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificationauthority)

[Property](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertificationauthority-get_property)