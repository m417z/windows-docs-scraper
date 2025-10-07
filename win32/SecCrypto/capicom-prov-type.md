# CAPICOM\_PROV\_TYPE enumeration

The **CAPICOM\_PROV\_TYPE** enumeration specifies the type of [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP).

## Members

| Member | Description | Value |
|------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------|
| **CAPICOM\_PROV\_RSA\_FULL** | The full [*RSA*](https://learn.microsoft.com/windows/win32/secgloss/r-gly) CSP. This provider type supports both [*digital signatures*](https://learn.microsoft.com/windows/win32/secgloss/d-gly) and data [*encryption*](https://learn.microsoft.com/windows/win32/secgloss/e-gly).<br> | 1 |
| **CAPICOM\_PROV\_RSA\_SIG** | The subset of the RSA CSP that supports only those functions and algorithms that are required for hashes and digital signatures.<br> | 2 |
| **CAPICOM\_PROV\_DSS** | The [*Digital Signature Standard*](https://learn.microsoft.com/windows/win32/secgloss/d-gly) (DSS) CSP. This provider type supports only hashes and digital signatures. DSS uses the [*Digital Signature Algorithm*](https://learn.microsoft.com/windows/win32/secgloss/d-gly) (DSA).<br> | 3 |
| **CAPICOM\_PROV\_FORTEZZA** | The CSP that contains the cryptographic protocols and algorithms owned by the [*National Institute of Standards and Technology*](https://learn.microsoft.com/windows/win32/secgloss/n-gly) (NIST).<br> | 4 |
| **CAPICOM\_PROV\_MS\_EXCHANGE** | The CSP that was designed for the cryptographic needs of Exchange and other applications that are compatible with Microsoft Mail.<br> | 5 |
| **CAPICOM\_PROV\_SSL** | The CSP that supports the [*Secure Sockets Layer*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) (SSL) protocol.<br> | 6 |
| **CAPICOM\_PROV\_RSA\_SCHANNEL** | The CSP that supports both [*RSA*](https://learn.microsoft.com/windows/win32/secgloss/r-gly) and [*Schannel*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) protocols.<br> | 12 |
| **CAPICOM\_PROV\_DSS\_DH** | The CSP that supports both DSS and [*Diffie-Hellman*](https://learn.microsoft.com/windows/win32/secgloss/d-gly) protocols.<br> | 13 |
| **CAPICOM\_PROV\_EC\_ECDSA\_SIG** | The CSP that supports the Elliptic Curve Digital Signature Algorithm (ECDSA) functions and algorithms required for digital signatures.<br> | 14 |
| **CAPICOM\_PROV\_EC\_ECNRA\_SIG** | The CSP that supports the Elliptic Curve Nyberg-Rueppel Analog (ECNRA) functions and algorithms required for digital signatures.<br> | 15 |
| **CAPICOM\_PROV\_EC\_ECDSA\_FULL** | The CSP that supports the full ECDSA.<br> | 16 |
| **CAPICOM\_PROV\_EC\_ECNRA\_FULL** | The CSP that supports the full ECNRA.<br> | 17 |
| **CAPICOM\_PROV\_DH\_SCHANNEL** | The CSP that supports both [*Diffie-Hellman*](https://learn.microsoft.com/windows/win32/secgloss/d-gly) and [*Schannel*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) protocols.<br> | 18 |
| **CAPICOM\_PROV\_SPYRUS\_LYNKS** | The CSP that supports the SPYRUS LYNKS Card device.<br> | 20 |
| **CAPICOM\_PROV\_RNG** | The CSP that handles random number generation.<br> | 21 |
| **CAPICOM\_PROV\_INTEL\_SEC** | The CSP that provides Intel security.<br> | 22 |
| **CAPICOM\_PROV\_REPLACE\_OWF** | The CSP that supports replacement of the manner in which one-way formats are generated from passwords.<br> | 23 |
| **CAPICOM\_PROV\_RSA\_AES** | The CSP that supports both digital signatures and data encryption using the Advanced Encryption Standard ([*AES*](https://learn.microsoft.com/windows/win32/secgloss/a-gly)) algorithm.<br> | 24 |

## Remarks

The **CAPICOM\_PROV\_TYPE** enumeration is used by the following methods and properties:

- [**PrivateKey.ProviderType**](https://learn.microsoft.com/windows/win32/seccrypto/privatekey-providertype) property.
- [**PrivateKey.Open**](https://learn.microsoft.com/windows/win32/seccrypto/privatekey-open) method.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

