# D3DCONTENTPROTECTIONCAPS structure

## Description

Describes the content protection capabilities of a display driver. To get the capabilities, call [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps).

## Members

### `Caps`

Bitwise **OR** of zero or more flags.

| Value | Meaning |
| --- | --- |
| **D3DCPCAPS_SOFTWARE**<br><br>0x00000001 | The encryption is implemented in software by the driver. |
| **D3DCPCAPS_HARDWARE**<br><br>0x00000002 | The encryption is implemented in hardware by the GPU. |
| **D3DCPCAPS_PROTECTIONALWAYSON**<br><br>0x00000004 | Content protection is always applied to a protected Direct3D surface, regardless of whether the application explicitly enables content protection. |
| **D3DCPCAPS_PARTIALDECRYPTION**<br><br>0x00000008 | The driver can use partially encrypted buffers. If this capability is not present, the entire buffer must be either encrypted or clear. |
| **D3DCPCAPS_CONTENTKEY**<br><br>0x00000010 | The driver can encrypt data using a separate content key that is encrypted using the session key. For more information, see [IDirect3DCryptoSession9::DecryptionBlt](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-decryptionblt). |
| **D3DCPCAPS_FRESHENSESSIONKEY**<br><br>0x00000020 | The driver can refresh the session key without renegotiating the key. To refresh the session key, call [IDirect3DCryptoSession9::StartSessionKeyRefresh](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-startsessionkeyrefresh). |
| **D3DCPCAPS_ENCRYPTEDREADBACK**<br><br>0x00000040 | The driver can read back encrypted data from a protected surface, using the [IDirect3DCryptoSession9::EncryptionBlt](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-encryptionblt) method. |
| **D3DCPCAPS_ENCRYPTEDREADBACKKEY**<br><br>0x00000080 | The driver requires a separate key to read encrypted data from a protected surface. To get this second key, call [IDirect3DCryptoSession9::GetEncryptionBltKey](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-getencryptionbltkey). |
| **D3DCPCAPS_SEQUENTIAL_CTR_IV**<br><br>0x00000100 | If the encryption type is **D3DCRYPTOTYPE_AES128_CTR**, the application must use a sequential count in the [DXVA2_AES_CTR_IV](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_aes_ctr_iv) structure. For more information, see the remarks for **DXVA2_AES_CTR_IV**. |

### `KeyExchangeType`

Specifies the type of key exchange required to negotiate the session key. The following GUIDs are defined.

| Value | Meaning |
| --- | --- |
| **D3DKEYEXCHANGE_RSAES_OAEP** | The decoder encrypts the session key using RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP). |
| **D3DKEYEXCHANGE_DXVA** | Use the key exchange mechanism defined for DirectX Video Acceleration 2 (DXVA-2). |

### `BufferAlignmentStart`

The memory alignment required for buffers used by the GPU cryptographic engine. If the application uses a system memory buffer to pass encrypted content to the GPU, or to read back encrypted content from the GPU, the buffer's starting address must be a multiple of this value.

### `BlockAlignmentSize`

The block alignment required by the GPU cryptographic engine. The size of data to be encrypted must be a multiple of this value.

### `ProtectedMemorySize`

The total amount of memory that can be used to hold protected surfaces.

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps)