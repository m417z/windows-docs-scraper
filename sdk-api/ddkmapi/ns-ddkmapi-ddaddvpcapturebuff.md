# DDADDVPCAPTUREBUFF structure

## Description

The DDADDVPCAPTUREBUFF structure contains the information required to add a new buffer to the internal capture queue.

## Members

### `hCapture`

Handle to the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

### `dwFlags`

Indicates whether the destination buffer exists in regular system memory or nonlocal display memory (AGP). This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDADDBUFF_INVERT | The buffer is to be inverted during capture. |
| DDADDBUFF_NONLOCALVIDMEM | The destination buffer exists in nonlocal display memory. |
| DDADDBUFF_SYSTEMMEMORY | The destination buffer exists in system memory. |

### `pMDL`

Points to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/) (defined in *wdm.h*) that describes the physical pages of the destination buffer.

### `pKEvent`

Points to a KEVENT that the kernel-mode video transport sets when the destination has been filled.

### `lpBuffInfo`

Points to a [DDCAPBUFFINFO](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddcapbuffinfo) structure that the kernel-mode video transport fills in before setting the KEVENT.

## See also

[DDCAPBUFFINFO](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddcapbuffinfo)

[DD_DXAPI_ADDVPCAPTUREBUFFER](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550599(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)