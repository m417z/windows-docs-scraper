# D3D11_1DDIARG_CREATECRYPTOSESSION structure

## Description

Specifies the attributes of the cryptographic session to be created by the user-mode driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

## Members

### `CryptoType`

a GUID that indicates the encryption type, which the driver uses for the encryption session that the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function creates. The GUID can be one of the following:

|Value|Meaning|
|--- |--- |
|D3D11_1DDI_CRYPTO_TYPE_AES128_CTR|A 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher.|
|D3D11_1DDI_CRYPTO_TYPE_PROPRIETARY|A proprietary encryption algorithm.|

### `DecodeProfile`

A GUID that specifies the DirectX Video Acceleration (DXVA) decode profile that the driver uses for the encryption session that the driver's [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function creates. For a list of possible values, see **CreateCryptoSession**. If DXVA decoding will not be used, set this parameter to **NULL_GUID**.

### `KeyExchangeType`

A GUID that specifies the type of key exchange.
The following GUID is defined.

| **Value** | **Meaning** |
|:---|:---|
| **D3D11_1DDI_KEY_EXCHANGE_RSAES_OAEP** | The caller will create the session key, encrypt it with RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP) by using the driver's public key, and pass the session key to the driver. |
| **D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION** | The crypto session will be used purely for communication between user mode DRM component and the secure execution environment.<br>When this GUID is specified, the following DDIs should not be called for the crypto session:<br> [GetCertificateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificatesize), [GetCertificate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificate), [EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt), [DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt), [StartSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_startsessionkeyrefresh), [FinishSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_finishsessionkeyrefresh), [GetEncryptionBltKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getencryptionbltkey)<br>The DRM commands are sent to the user mode driver by calling the [NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange) function where the data passed is a pointer to a [D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_data) structure. |