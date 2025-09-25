# ICspInformation::get_KeySpec

## Description

The **KeySpec** property retrieves a value that specifies the intended use of the algorithms supported by the provider. This property is web enabled.

This property is read-only.

## Parameters

## Remarks

The value retrieved can be 0, 1, 2, or 3. If the value is 0 (XCN_AT_NONE), the provider is a Cryptography API: Next Generation (CNG) provider. The values associated with the providers distributed by Microsoft are listed in the following table. Some of these providers may not be included on all operating systems and others may be included instead.

| Provider | KeySpec value |
| --- | --- |
| Microsoft Software Key Storage Provider | 0 |
| Microsoft Smart Card Key Storage Provider | 0 |
| Microsoft Base Cryptographic Provider v1.0 | 3 |
| Microsoft Base DSS and Diffie-Hellman Cryptographic Provider | 3 |
| Microsoft Base DSS Cryptographic Provider | 2 |
| Microsoft Base Smart Card Crypto Provider | 3 |
| Microsoft DH Schannel Cryptographic Provider | 3 |
| Microsoft Enhanced Cryptographic Provider v1.0 | 3 |
| Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider | 3 |
| Microsoft Enhanced RSA and AES Cryptographic Provider | 3 |
| Microsoft RSA Schannel Cryptographic Provider | 1 |
| Microsoft Strong Cryptographic Provider | 3 |

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)