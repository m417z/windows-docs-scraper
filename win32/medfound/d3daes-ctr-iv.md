# D3DAES\_CTR\_IV structure

Contains an initialization vector (IV) for 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher encryption.

## Members

**IV**

The IV, in big-endian format.

**Count**

The block count, in big-endian format.

## Remarks

The **D3DAES\_CTR\_IV** structure and the [**DXVA2\_AES\_CTR\_IV**](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_aes_ctr_iv) structure are equivalent.

For details, see [**DXVA2\_AES\_CTR\_IV**](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_aes_ctr_iv).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h (include D3d9.h) |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

