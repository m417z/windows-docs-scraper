# IKEV2_TUNNEL_CONFIG_PARAMS2 structure

## Description

Gets or sets tunnel parameters for Internet Key Exchange version 2 (IKEv2) devices.

Do not use the **IKEV2_TUNNEL_CONFIG_PARAMS2** structure directly in your code; using [IKEV2_TUNNEL_CONFIG_PARAMS](https://learn.microsoft.com/windows/desktop/RRAS/router-management-data-types) instead ensures that the proper version, based on the operating system the code in compiled under, is used.

## Members

### `dwIdleTimeout`

A value that specifies the time, in seconds, after which the connection will be disconnected if there is no traffic.

### `dwNetworkBlackoutTime`

A value that specifies the retransmission timeout for IKEv2 request packets. IKEv2 expects a response for every request packet sent, this value specifies the time after which the connection is deleted in case a response is not received.

### `dwSaLifeTime`

A value that specifies the lifetime, in seconds, of a security association (SA), after which the SA is no longer valid.

### `dwSaDataSizeForRenegotiation`

A value that specifies the number of kilobytes that are allowed to be transferred using a SA before it must be renegotiated.

### `dwConfigOptions`

Not implemented. Must be set to 0.

### `dwTotalCertificates`

A value that specifies the number of certificates in **certificateNames**.

### `certificateNames`

An array of CERT_NAME_BLOB structures that contain X.509 public key infrastructure certificates.

### `machineCertificateName`

The encryption type to be used for IKEv2.

### `dwEncryptionType`

A value that specifies the encryption type to be negotiated during the SA negotiation for the IKE2 tunnel based VPN connections. The *dwEncryptionType* parameter must have one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | RRAS will not negotiate encryption. |
| 1 | RRAS requests encryption during negotiation. Negotiation will succeed even if remote RRAS does not support encryption. |
| 2 | RRAS requires encryption to be negotiated. |
| 3 | RRAS requires maximum strength encryption to be negotiated. |

### `customPolicy`

A value that specifies the custom IKEv2 configurations to be used during the SA negotiation. If **customPolicy** is set to **NULL**, no custom IKEv2 configuration is available.