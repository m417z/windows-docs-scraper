# CREDENTIAL_TARGET_INFORMATIONA structure

## Description

The **CREDENTIAL_TARGET_INFORMATION** structure contains the target computer's name, domain, and tree.

## Members

### `TargetName`

Name of the target server as specified by the caller accessing the target. It is typically the NetBIOS or DNS name of the target server.

### `NetbiosServerName`

NetBIOS name of the target server. If the name is not known, this member can be **NULL**.

### `DnsServerName`

DNS name of the target server. If the name is not known, this member can be **NULL**.

### `NetbiosDomainName`

NetBIOS name of the target server's domain. If the name is not known, this member can be **NULL**. If the target server is a member of a workgroup, this member must be **NULL**.

### `DnsDomainName`

DNS name of the target server's domain. If the name is not known, this member can be **NULL**. If the target server is a member of a workgroup, this member must be **NULL**.

### `DnsTreeName`

DNS name of the target server's tree. If the tree name is not known, this member can be **NULL**. If the target server is a member of a workgroup, this member must be **NULL**.

### `PackageName`

Name of the authentication package that determined the values **NetbiosServerName**, **DnsServerName**, **NetbiosDomainName**, **DnsDomainName**, and **DnsTreeName** as a function of **TargetName**. This member can be passed to [AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) as the package name.

### `Flags`

Attributes of the target.

* CRED_TI_SERVER_FORMAT_UNKNOWN

  (1) — Set if the authentication package cannot determine whether the server name is a DNS name or a NetBIOS name. In that case, the **NetbiosServerName** member is set to **NULL** and the **DnsServerName** member is set to the server name of unknown format.
* CRED_TI_DOMAIN_FORMAT_UNKNOWN

  (2) — Set if the authentication package cannot determine whether the domain name is a DNS name or a NetBIOS name. In that case, the **NetbiosDomainName** member is set to **NULL** and the **DnsDomainName** member is set to the domain name of unknown format.
* CRED_TI_ONLY_PASSWORD_REQUIRED

  (4) — Set if the authentication package has determined that the server only needs a password to authenticate. The caller can use this flag to prompt only for a password and not a user name.

  Stored credentials require a UserName member. A value of <*DnsServerName*>\Guest or <*NetbiosServerName*>\Guest should be used for these servers.

### `CredTypeCount`

Number of elements in the **CredTypes** array.

### `CredTypes`

Array specifying the credential types acceptable by the authentication package used by the target server. Each element is one of the CRED_TYPE_* defines. The order of this array specifies the preference order of the authentication package. More preferable types are specified earlier in the list.

## Remarks

> [!NOTE]
> The wincred.h header defines CREDENTIAL_TARGET_INFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).