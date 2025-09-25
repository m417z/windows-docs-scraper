## Description

Contains the traffic secrets for a connection.

## Members

### `SymmetricAlgId`

THe negotiated symmetric key algorithm (e.g. **BCRYPT_AES_ALGORITHM**).

### `ChainingMode`

The negotiated symmetric key algorithm chaining mode (e.g. **BCRYPT_CHAIN_MODE_GCM** or **BCRYPT_CHAIN_MODE_CCM**).

### `HashAlgId`

The negotiated hash algorithm (e.g. **BCRYPT_SHA256_ALGORITHM** or **BCRYPT_SHA384_ALGORITHM**).

### `KeySize`

They size (in bytes) of the symmetric key to derive from this traffic secret.

### `IvSize`

The size (in bytes) of the IV to derive from this traffic secret.

### `MsgSequenceStart`

The offset of the first byte of the TLS message sequence to be protected with a key derived from **TrafficSecret**. Use **0** to indicate the first byte of the buffer.

### `MsgSequenceEnd`

The offset of the last byte of the TLS message sequence to be protected with a key derived from **TrafficSecret**. Use **0** if the secret is for the encryption of application data or decryption of incoming records.

### `TrafficSecretType`

The type of traffic secret from the [TRAFFIC_SECRET_TYPE](https://learn.microsoft.com/windows/win32/api/sspi/ne-sspi-sec_traffic_secret_type) enumeration.

### `TrafficSecretSize`

The size (in bytes) of the traffic secret.

### `TrafficSecret`

Traffic secret of type **TrafficSecretType**, **TrafficSecretSize** bytes long, used to derive write key and IV for message protection.

## Remarks

## See also

[TRAFFIC_SECRET_TYPE](https://learn.microsoft.com/windows/win32/api/sspi/ne-sspi-sec_traffic_secret_type)