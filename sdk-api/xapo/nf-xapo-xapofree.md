# XAPOFree macro

## Description

Macro used to free memory allocated with the [XAPOAlloc](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapoalloc) macro.

## Parameters

### `p`

Pointer to the memory block to be freed.

## Remarks

**XAPOFree** and [XAPOAlloc](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapoalloc) are memory allocation macros that allow one module to allocate memory and another to free it, by guaranteeing that the same heap manager is used regardless of differences between the build environments of the two modules.

| Xbox 360 |
| --- |
| **XAPOFree** and [XAPOAlloc](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapoalloc) resolve to **XMemAlloc** and **XMemFree** on Xbox 360. |

| Windows |
| --- |
| **XAPOFree** and [XAPOAlloc](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapoalloc) resolve to **CoTaskMemAlloc** and **CoTaskMemFree**. |

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Macros](https://learn.microsoft.com/windows/desktop/xaudio2/macros)