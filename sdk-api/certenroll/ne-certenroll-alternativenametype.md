# AlternativeNameType enumeration

## Description

The **AlternativeNameType** enumeration specifies the alternative name types that can be specified when initializing an [IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename) object. Alternative names are used to create a version 3 [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) **AlternativeNames** extension. You can create this extension by using the [IX509ExtensionAlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionalternativenames) interface.

## Constants

### `XCN_CERT_ALT_NAME_UNKNOWN:0`

The name type is not identified.

### `XCN_CERT_ALT_NAME_OTHER_NAME:1`

The name consists of an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and a byte array that contains the name value.

### `XCN_CERT_ALT_NAME_RFC822_NAME:2`

The name is an email address such as *someone@example.com*.

### `XCN_CERT_ALT_NAME_DNS_NAME:3`

The name is a Domain Name System (DNS) name such as *MyDomain.Microsoft.com*. The format of a DNS name is *Host.Entity.Domain*. For more information about DNS, see RFC 1034 (Domain Names—Concepts and Facilities), and RFC 1035 (Domain Names—Implementation and Specification).

### `XCN_CERT_ALT_NAME_X400_ADDRESS:4`

### `XCN_CERT_ALT_NAME_DIRECTORY_NAME:5`

The name is an [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) directory name such as *CN=administrators,CN=users,DC=nttest,DC=microsoft,DC=com*.

### `XCN_CERT_ALT_NAME_EDI_PARTY_NAME:6`

### `XCN_CERT_ALT_NAME_URL:7`

The name is a URL such as *http://www.adatum.com/*.

### `XCN_CERT_ALT_NAME_IP_ADDRESS:8`

The name is an Internet Protocol (IP) address in dotted decimal format *123.456.789.123*.

### `XCN_CERT_ALT_NAME_REGISTERED_ID:9`

The name is an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) registered with the International Standards Organization (ISO).

### `XCN_CERT_ALT_NAME_GUID:10`

The name is a Directory Service Agent GUID. The GUID identifies a server to the Active Directory replication system as a domain controller.

### `XCN_CERT_ALT_NAME_USER_PRINCIPLE_NAME:11`

The name is a [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN). A UPN is a user logon name in email address format. That is, a UPN consists of a shorthand name for a user account followed by the DNS name of the Active Directory tree in which the user object resides. It has the form *UserName@DNS_suffix*. An example is *UserName@Microsoft.com* where Microsoft.com is the DNS suffix and *UserName* is a placeholder for a shorthand name assigned by Microsoft to a user account.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename)

[IX509ExtensionAlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionalternativenames)