# CREDENTIALW structure

## Description

The **CREDENTIAL** structure contains an individual credential.

## Members

### `Flags`

A bit member that identifies characteristics of the credential. Undefined bits should be initialized as zero and not otherwise altered to permit future enhancement.

| Value | Meaning |
| --- | --- |
| ****CRED_FLAGS_PROMPT_NOW****<br><br>2 (0x2) | Bit set if the credential does not persist the **CredentialBlob** and the credential has not been written during this logon session. This bit is ignored on input and is set automatically when queried.<br><br>If **Type** is **CRED_TYPE_DOMAIN_CERTIFICATE**, the **CredentialBlob** is not persisted across logon sessions because the PIN of a certificate is very sensitive information. Indeed, when the credential is written to credential manager, the PIN is passed to the CSP associated with the certificate. The CSP will enforce a PIN retention policy appropriate to the certificate.<br><br>If **Type** is **CRED_TYPE_DOMAIN_PASSWORD** or **CRED_TYPE_DOMAIN_CERTIFICATE**, an authentication package always fails an authentication attempt when using credentials marked as **CRED_FLAGS_PROMPT_NOW**. The application (typically through the key ring UI) prompts the user for the password. The application saves the credential and retries the authentication. Because the credential has been recently written, the authentication package now gets a credential that is not marked as CRED_FLAGS_PROMPT_NOW. |
| ****CRED_FLAGS_USERNAME_TARGET****<br><br>4 (0x4) | Bit is set if this credential has a **TargetName** member set to the same value as the **UserName** member. Such a credential is one designed to store the **CredentialBlob** for a specific user. For more information, see the [CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala) function.<br><br>This bit can only be specified if **Type** is **CRED_TYPE_DOMAIN_PASSWORD** or **CRED_TYPE_DOMAIN_CERTIFICATE**. |

### `Type`

The type of the credential. This member cannot be changed after the credential is created. The following values are valid.

| Value | Meaning |
| --- | --- |
| ****CRED_TYPE_GENERIC****<br><br>1 (0x1) | The credential is a generic credential. The credential will not be used by any particular authentication package. The credential will be stored securely but has no other significant characteristics. |
| ****CRED_TYPE_DOMAIN_PASSWORD****<br><br>2 (0x2) | The credential is a password credential and is specific to Microsoft's authentication packages. The NTLM, Kerberos, and Negotiate authentication packages will automatically use this credential when connecting to the named target. |
| ****CRED_TYPE_DOMAIN_CERTIFICATE****<br><br>3 (0x3) | The credential is a certificate credential and is specific to Microsoft's authentication packages. The Kerberos, Negotiate, and Schannel authentication packages automatically use this credential when connecting to the named target. |
| ****CRED_TYPE_DOMAIN_VISIBLE_PASSWORD****<br><br>4 (0x4) | This value is no longer supported.<br><br>**Windows Server 2003 and Windows XP:** The credential is a password credential and is specific to authentication packages from Microsoft. The Passport authentication package will automatically use this credential when connecting to the named target.<br><br>Additional values will be defined in the future. Applications should be written to allow for credential types they do not understand. |
| **CRED_TYPE_GENERIC_CERTIFICATE**<br><br>5 (0x5) | The credential is a certificate credential that is a generic authentication package. <br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **CRED_TYPE_DOMAIN_EXTENDED**<br><br>6 (0x6) | The credential is supported by extended Negotiate packages.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **CRED_TYPE_MAXIMUM**<br><br>7 (0x7) | The maximum number of supported credential types.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **CRED_TYPE_MAXIMUM_EX**<br><br>CRED_TYPE_MAXIMUM+1000 | The extended maximum number of supported credential types that now allow new applications to run on older operating systems.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

### `TargetName.string`

### `TargetName.max_is`

### `TargetName.max_is.CRED_MAX_GENERIC_TARGET_NAME_LENGTH-1`

### `TargetName`

The name of the credential. The **TargetName** and **Type** members uniquely identify the credential. This member cannot be changed after the credential is created. Instead, the credential with the old name should be deleted and the credential with the new name created.

If **Type** is **CRED_TYPE_DOMAIN_PASSWORD** or **CRED_TYPE_DOMAIN_CERTIFICATE**, this member identifies the server or servers that the credential is to be used for. The member is either a NetBIOS or DNS server name, a DNS host name suffix that contains a wildcard character, a NetBIOS or DNS domain name that contains a wildcard character sequence, or an asterisk.

If **TargetName** is a DNS host name, the **TargetAlias** member can be the NetBIOS name of the host.

If the **TargetName** is a DNS host name suffix that contains a wildcard character, the leftmost label of the DNS host name is an asterisk (\*), which denotes that the target name is any server whose name ends in the specified name, for example, \*.microsoft.com.

If the **TargetName** is a domain name that contains a wildcard character sequence, the syntax is the domain name followed by a backslash and asterisk (\\*), which denotes that the target name is any server that is a member of the named domain (or realm).

If **TargetName** is a DNS domain name that contains a wildcard character sequence, the **TargetAlias** member can be a NetBIOS domain name that uses a wildcard sequence for the same domain.

If **TargetName** specifies a DFS share, for example, _DfsRoot\\DfsShare_, then this credential matches the specific DFS share and any servers reached through that DFS share.

If **TargetName** is a single asterisk (\*), this credential matches any server name.

If **TargetName** is CRED_SESSION_WILDCARD_NAME, this credential matches any server name. This credential matches before a single asterisk and is only valid if **Persist** is **CRED_PERSIST_SESSION**. The credential can be set by applications that want to temporarily override the default credential.

This member cannot be longer than **CRED_MAX_DOMAIN_TARGET_NAME_LENGTH** (337) characters.

If the **Type** is CRED_TYPE_GENERIC, this member should identify the service that uses the credential in addition to the actual target. Microsoft suggests the name be prefixed by the name of the company implementing the service. Microsoft will use the prefix "Microsoft". Services written by Microsoft should append their service name, for example **Microsoft_RAS_***TargetName*. This member cannot be longer than **CRED_MAX_GENERIC_TARGET_NAME_LENGTH** (32767) characters.

This member is case-insensitive.

### `Comment.string`

### `Comment.max_is`

### `Comment.max_is.CRED_MAX_STRING_LENGTH-1`

### `Comment`

A string comment from the user that describes this credential. This member cannot be longer than **CRED_MAX_STRING_LENGTH** (256) characters.

### `LastWritten`

The time, in Coordinated Universal Time (Greenwich Mean Time), of the last modification of the credential. For write operations, the value of this member is ignored.

### `CredentialBlobSize`

The size, in bytes, of the **CredentialBlob** member. This member cannot be larger than **CRED_MAX_CREDENTIAL_BLOB_SIZE** (5*512) bytes.

### `CredentialBlobSize.range`

### `CredentialBlobSize.range.0`

### `CredentialBlobSize.range.CRED_MAX_CREDENTIAL_BLOB_SIZE`

### `CredentialBlob`

Secret data for the credential. The **CredentialBlob** member can be both read and written.

If the **Type** member is **CRED_TYPE_DOMAIN_PASSWORD**, this member contains the plaintext Unicode password for **UserName**. The **CredentialBlob** and **CredentialBlobSize** members do not include a trailing zero character. Also, for **CRED_TYPE_DOMAIN_PASSWORD**, this member can only be read by the authentication packages.

If the **Type** member is **CRED_TYPE_DOMAIN_CERTIFICATE**, this member contains the clear test Unicode PIN for **UserName**. The **CredentialBlob** and **CredentialBlobSize** members do not include a trailing zero character. Also, this member can only be read by the authentication packages.

If the **Type** member is **CRED_TYPE_GENERIC**, this member is defined by the application.

Credentials are expected to be portable. Applications should ensure that the data in **CredentialBlob** is portable. The application defines the byte-endian and alignment of the data in **CredentialBlob**.

### `CredentialBlob.size_is`

### `CredentialBlob.size_is.CredentialBlobSize`

### `Persist`

Defines the persistence of this credential. This member can be read and written.

| Value | Meaning |
| --- | --- |
| ****CRED_PERSIST_SESSION****<br><br>1 (0x1) | The credential persists for the life of the logon session. It will not be visible to other logon sessions of this same user. It will not exist after this user logs off and back on. |
| ****CRED_PERSIST_LOCAL_MACHINE****<br><br>2 (0x2) | The credential persists for all subsequent logon sessions on this same computer. It is visible to other logon sessions of this same user on this same computer and not visible to logon sessions for this user on other computers.<br><br>**Windows Vista Home Basic, Windows Vista Home Premium, Windows Vista Starter and Windows XP Home Edition:** This value is not supported. |
| ****CRED_PERSIST_ENTERPRISE****<br><br>3 (0x3) | The credential persists for all subsequent logon sessions on this same computer. It is visible to other logon sessions of this same user on this same computer and to logon sessions for this user on other computers.<br><br>This option can be implemented as locally persisted credential if the administrator or user configures the user account to not have roam-able state. For instance, if the user has no roaming profile, the credential will only persist locally.<br><br>**Windows Vista Home Basic, Windows Vista Home Premium, Windows Vista Starter and Windows XP Home Edition:** This value is not supported. |

### `AttributeCount`

The number of application-defined attributes to be associated with the credential. This member can be read and written. Its value cannot be greater than **CRED_MAX_ATTRIBUTES** (64).

### `AttributeCount.range`

### `AttributeCount.range.0`

### `AttributeCount.range.CRED_MAX_ATTRIBUTES`

### `Attributes`

Application-defined attributes that are associated with the credential. This member can be read and written.

### `Attributes.size_is`

### `Attributes.size_is.AttributeCount`

### `TargetAlias.string`

### `TargetAlias.max_is`

### `TargetAlias.max_is.CRED_MAX_STRING_LENGTH-1`

### `TargetAlias`

Alias for the **TargetName** member. This member can be read and written. It cannot be longer than **CRED_MAX_STRING_LENGTH** (256) characters.

If the credential **Type** is **CRED_TYPE_GENERIC**, this member can be non-**NULL**, but the credential manager ignores the member.

### `UserName.string`

### `UserName.max_is`

### `UserName.max_is.CRED_MAX_USERNAME_LENGTH-1`

### `UserName`

The user name of the account used to connect to **TargetName**.

If the credential **Type** is **CRED_TYPE_DOMAIN_PASSWORD**, this member can be either a _DomainName\\UserName_ or a UPN.

If the credential **Type** is **CRED_TYPE_DOMAIN_CERTIFICATE**, this member must be a marshaled certificate reference created by calling [CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala) with a CertCredential.

If the credential **Type** is **CRED_TYPE_GENERIC**, this member can be non-**NULL**, but the credential manager ignores the member.

This member cannot be longer than **CRED_MAX_USERNAME_LENGTH** (513) characters.

## Remarks

> [!NOTE]
> The wincred.h header defines CREDENTIAL as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).