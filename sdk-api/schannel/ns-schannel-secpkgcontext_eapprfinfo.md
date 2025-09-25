# SecPkgContext_EapPrfInfo structure

## Description

The **SecPkgContext_EapPrfInfo** structure specifies the pseudorandom function (PRF) and extracts key data used by the Extensible Authentication Protocol (EAP) [Transport Layer Security protocol](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) (TLS) Authentication Protocol. For information about the EAP TLS Authentication Protocol, see [http://www.ietf.org/rfc/rfc2716.txt](https://www.ietf.org/rfc/rfc2716.txt).

## Members

### `dwVersion`

Reserved. Must be set to zero.

### `cbPrfData`

The size, in bytes, of the *pbPrfData* array.

#### pbPrfData

A **DWORD** value that specifies the pseudorandom function and key data used by the EAP protocol. The following are possible values.

| Value | Meaning |
| --- | --- |
| **PPP EAP TLS Key Data**<br><br>0x00 | PRF(master secret, "client EAP encryption", client_random + server_random) |
| **EAP-TTLSv0 Keying Material**<br><br>0x01 | PRF(master_secret, "ttls keying material", server_random + client_random) |
| **EAP-TTLSv0 Challenge Data**<br><br>0x02 | PRF(master_secret, "ttls challenge", server_random + client_random) |
| **EAP-FAST Keying Material**<br><br>0x03 | PRF(master_secret, "key expansion", server_random + client_random) |

### `pbPrfData`