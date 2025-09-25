# D3D11_1DDI_CONTENT_PROTECTION_CAPS enumeration

## Description

Describes content-protection capabilities.

## Constants

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_SOFTWARE`

The encryption is implemented in software by the driver.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_HARDWARE`

The encryption is implemented in hardware by the GPU.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_PROTECTION_ALWAYS_ON`

Content protection is always applied to a protected surface, regardless of whether the application explicitly enables protection.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_PARTIAL_DECRYPTION`

The driver can use partially encrypted buffers. If this capability is not present, the entire buffer must be either encrypted or clear.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_CONTENT_KEY`

The driver can encrypt data using a separate content key that is encrypted using the session key.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_FRESHEN_SESSION_KEY`

The driver can refresh the session key without renegotiating the key.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_ENCRYPTED_READ_BACK`

The driver can read back encrypted data from a protected surface. For more information, see [EncryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_encryptionblt).

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_ENCRYPTED_READ_BACK_KEY`

The driver requires a separate key to read encrypted data from a protected surface.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_SEQUENTIAL_CTR_IV`

If the encryption type is **D3D11_1DDI_CRYPTO_TYPE_AES128_CTR**, the application must use a sequential count in the [D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv) structure. For more information, see the Remarks for the [EncryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_encryptionblt) function.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_ENCRYPT_SLICEDATA_ONLY`

The driver supports encrypted slice data, but does not support any other encrypted data in the DirectX Video Accelerator (DXVA) 2 compressed buffer. The caller should not encrypt any data within the buffer other than the slice data.

### `D3D11_1DDI_CONTENT_PROTECTION_CAPS_DECRYPTION_BLT`

The driver supports calls to the [DecryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_decryptionblt) function.

### `D3DWDDM2_0DDI_CONTENT_PROTECTION_CAPS_HARDWARE_PROTECT_UNCOMPRESSED`

The hardware supports the protection of specific resources using the WDDM 2.0 and later versions of the Graphics Content Protection DDI. This protection means:

* The contents of a protected allocation can never be read by the CPU.
* The hardware can ensure that a protected resource cannot be copied to an unprotected resource.

Supported starting with Windows 10.

### `D3DWDDM2_0DDI_CONTENT_PROTECTION_CAPS_HARDWARE_PROTECTED_MEMORY_PAGEABLE`

The physical pages of a protected resource can be evicted and potentially paged to disk in low memory conditions without losing the contents of the resource when paged back in.

Supported starting with Windows 10.

### `D3DWDDM2_0DDI_CONTENT_PROTECTION_CAPS_HARDWARE_PROTECTED_MEMORY_TRANSITION`

The hardware or driver can transition allocations between protected and unprotected states by calling [SetHardwareProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_sethardwareprotection) without requiring the allocation to be re-created.

Supported starting with Windows 10.

### `D3DWDDM2_0DDI_CONTENT_PROTECTION_CAPS_HARDWARE_TEARDOWN`

The hardware supports an automatic tear-down mechanism that could trigger hardware keys or protected content to become lost in some conditions. The application can register to know when these events occur.

Supported starting with Windows 10.

### `D3DWDDM2_0DDI_CONTENT_PROTECTION_CAPS_HARDWARE_DRM_COMMUNICATION`

The secure environment is tightly coupled with the GPU and an **ID3D11CryptoSession** should be used for communication between the user mode DRM component and the secure execution environment.

Supported starting with Windows 10.

## See also

[D3D11_1DDI_AES_CTR_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_aes_ctr_iv)

[DecryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_decryptionblt)

[EncryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_encryptionblt)

[SetHardwareProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_sethardwareprotection)