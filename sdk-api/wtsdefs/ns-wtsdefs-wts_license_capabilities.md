# WTS_LICENSE_CAPABILITIES structure

## Description

Contains information about the licensing capabilities of the client.

## Members

### `KeyExchangeAlg`

Contains an integer that specifies the encryption algorithm. This can be one of the following values.

#### WTS_KEY_EXCHANGE_ALG_RSA (1)

The RSA algorithm.

#### WTS_KEY_EXCHANGE_ALG_DH (2)

The Diffie-Hellman algorithm.

### `ProtocolVer`

An integer that specifies the supported licensing protocol. This must be **WTS_LICENSE_CURRENT_PROTOCOL_VERSION**.

### `fAuthenticateServer`

A Boolean value that specifies whether the client will authenticate the server.

### `CertType`

A [WTS_CERT_TYPE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wts_cert_type) enumeration value that specifies the type of the certificate used to obtain the license.

### `cbClientName`

An integer that contains the size, in bytes, of the client name specified by the **rgbClientName** member.

### `rgbClientName`

The client name, including a terminating null character.

## Remarks

This enumeration is used by the [RequestLicensingCapabilities](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocollicenseconnection-requestlicensingcapabilities) method.