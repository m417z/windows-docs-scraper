# D3DENCRYPTED\_BLOCK\_INFO structure

Specifies which bytes are encrypted in a protected video surface.

## Members

**NumEncryptedBytesAtBeginning**

The number of bytes that are encrypted at the start of the buffer.

**NumBytesInSkipPattern**

The number of bytes that are skipped after the first **NumEncryptedBytesAtBeginning** bytes, and then after each block of **NumBytesInEncryptPattern** bytes. Skipped bytes are not encrypted.

**NumBytesInEncryptPattern**

The number of bytes that are encrypted after each block of skipped bytes.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h (include D3d9.h) |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

