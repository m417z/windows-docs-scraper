# D3D11_CONTENT_PROTECTION_CAPS enumeration

## Description

Contains flags that describe content-protection capabilities.

## Constants

### `D3D11_CONTENT_PROTECTION_CAPS_SOFTWARE:0x1`

The content protection is implemented in software by the driver.

### `D3D11_CONTENT_PROTECTION_CAPS_HARDWARE:0x2`

The content protection is implemented in hardware by the GPU.

### `D3D11_CONTENT_PROTECTION_CAPS_PROTECTION_ALWAYS_ON:0x4`

Content protection is always applied to a protected surface, regardless of whether the application explicitly enables protection.

### `D3D11_CONTENT_PROTECTION_CAPS_PARTIAL_DECRYPTION:0x8`

The driver can use partially encrypted buffers. If this capability is not present, the entire buffer must be either encrypted or clear.

### `D3D11_CONTENT_PROTECTION_CAPS_CONTENT_KEY:0x10`

The driver can encrypt data using a separate content key that is encrypted using the session key.

### `D3D11_CONTENT_PROTECTION_CAPS_FRESHEN_SESSION_KEY:0x20`

The driver can refresh the session key without renegotiating the key.

### `D3D11_CONTENT_PROTECTION_CAPS_ENCRYPTED_READ_BACK:0x40`

The driver can read back encrypted data from a protected surface. For more information, see [ID3D11VideoContext::EncryptionBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-encryptionblt).

### `D3D11_CONTENT_PROTECTION_CAPS_ENCRYPTED_READ_BACK_KEY:0x80`

The driver requires a separate key to read encrypted data from a protected surface.

### `D3D11_CONTENT_PROTECTION_CAPS_SEQUENTIAL_CTR_IV:0x100`

If the encryption type is **D3DCRYPTOTYPE_AES128_CTR**, the application must use a sequential count in the [D3D11_AES_CTR_IV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_aes_ctr_iv) structure.

### `D3D11_CONTENT_PROTECTION_CAPS_ENCRYPT_SLICEDATA_ONLY:0x200`

The driver supports encrypted slice data, but does not support any other encrypted data in the compressed buffer. The caller should not encrypt any data within the buffer other than the slice data.

**Note** The driver should only report this flag for the specific profiles that have this limitation.

### `D3D11_CONTENT_PROTECTION_CAPS_DECRYPTION_BLT:0x400`

The driver can copy encrypted data from one resource to another, decrypting the data as part of the process.

### `D3D11_CONTENT_PROTECTION_CAPS_HARDWARE_PROTECT_UNCOMPRESSED:0x800`

The hardware supports the protection of specific resources. This means that:

* The contents of a protected allocation can never be read by the CPU.
* The hardware can ensure a protected resource cannot be copied to an unprotected resource.

**Note** This enumeration value is supported starting with Windows 10.

### `D3D11_CONTENT_PROTECTION_CAPS_HARDWARE_PROTECTED_MEMORY_PAGEABLE:0x1000`

Physical pages of a protected resource can be evicted and potentially paged to disk in low memory conditions without losing the contents of the resource when paged back in.

**Note** This enumeration value is supported starting with Windows 10.

### `D3D11_CONTENT_PROTECTION_CAPS_HARDWARE_TEARDOWN:0x2000`

The hardware supports an automatic teardown mechanism that could trigger hardware keys or protected content to become lost in some conditions. The application can register to be notified when these events occur.

**Note** This enumeration value is supported starting with Windows 10.

### `D3D11_CONTENT_PROTECTION_CAPS_HARDWARE_DRM_COMMUNICATION:0x4000`

The secure environment is tightly coupled with the GPU and an [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) should be used for communication between the user mode DRM component and the secure execution environment.

**Note** This enumeration value is supported starting with Windows 10.

### `D3D11_CONTENT_PROTECTION_CAPS_HARDWARE_DRM_COMMUNICATION_MULTI_THREADED:0x8000`

## See also

[D3D11_VIDEO_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_content_protection_caps)

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)