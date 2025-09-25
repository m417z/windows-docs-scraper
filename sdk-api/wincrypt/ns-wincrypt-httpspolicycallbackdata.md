# HTTPSPolicyCallbackData structure

## Description

The **SSL_EXTRA_CERT_CHAIN_POLICY_PARA** structure, also identified by the name **HTTPSPolicyCallbackData**, holds policy information used in the verification of [Secure Sockets Layer](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) client/server certificate chains.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.cbStruct`

**DWORD** value that specifies the number of bytes in this structure.

### `DUMMYUNIONNAME.cbSize`

**DWORD** value that specifies the size, in bytes, of this structure.

### `dwAuthType`

**DWORD** value that specifies the type of authentication. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AUTHTYPE_CLIENT**<br><br>1 | The client is being authenticated. |
| **AUTHTYPE_SERVER**<br><br>2 | The server is being authenticated. |

### `fdwChecks`

**DWORD** value that specifies certificate errors to ignore. This can be a bitwise combination of the following flags.

| Value | Meaning |
| --- | --- |
| **SECURITY_FLAG_IGNORE_REVOCATION**<br><br>0x00000080 | Ignore errors associated with a revoked certificate. |
| **SECURITY_FLAG_IGNORE_UNKNOWN_CA**<br><br>0x00000100 | Ignore errors associated with an unknown [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). |
| **SECURITY_FLAG_IGNORE_WRONG_USAGE**<br><br>0x00000200 | Ignore errors associated with the use of a certificate. |
| **SECURITY_FLAG_IGNORE_CERT_CN_INVALID**<br><br>0x00001000 | Ignore errors associated with a certificate that contains a common name that is not valid. |
| **SECURITY_FLAG_IGNORE_CERT_DATE_INVALID**<br><br>0x00002000 | Ignore errors associated with an expired certificate. |

### `pwszServerName`

A pointer to a null-terminated wide character string that contains the server name. This member is ignored if the value of the **dwAuthType** member is **AUTHTYPE_CLIENT**.

If the string is Punycode encoded, then the server name from the certificate, either the DNS name or common name, is converted to a Punycode encoded string. Matching is then performed, label-by-label if the name contains wildcards, or a case-insensitive exact match otherwise.

If the string contains Unicode characters outside of the ASCII character set and the subject name, either the DNS name or common name, is a Punycode encoded string then it is Punycode encoded before comparison.