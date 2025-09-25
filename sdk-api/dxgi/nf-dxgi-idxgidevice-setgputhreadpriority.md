# IDXGIDevice::SetGPUThreadPriority

## Description

Sets the GPU thread priority.

## Parameters

### `Priority`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that specifies the required GPU thread priority. See the [Remarks](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgidevice-setgputhreadpriority#remarks) section in this topic.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Return S_OK if successful; otherwise, returns E_INVALIDARG if the *Priority* parameter is invalid.

## Remarks

To use the **SetGPUThreadPriority** method, you should have a comprehensive understanding of GPU scheduling. If used inappropriately, the **SetGPUThreadPriority** method can impede rendering speed and result in a poor user experience, so profile your application to understand impact of priority change on application and on system.

The values for the *Priority* parameter function as follows:
**Priority Values Bit Definition:**

Bit 0-4 : Priority Value \
Bit 5-29 : Reserved \
Bit 30 : Absolute Priority Flag ( D3DKMT_SETCONTEXTSCHEDULINGPRIORITY_ABSOLUTE ), can be ORed with Priority Value Bits [4:0] (Only valid for Windows 10+, else not used)\
Bit 31 : Signed bit \

Bit 30 (Absolute Priority Flag) can be used to control the mode of operation for this API.

**Relative Priority Mode** : API will use this mode when bit 30 value is set to 0. In this mode, **Priority** value must be between -7 and 7, inclusive, where priority value 0 represents normal priority (Default for all contexts) and -7 represents Idle priority. Bit 31 is used to control sign of the priority.

**Absolute Priority Mode** : API will use this mode when bit 30 value is set to 1. In this mode, **Priority** value (for bits[4:0]) must be between 0 and 31. Meaning of these priority levels is described below. Use D3DKMT_SETCONTEXTSCHEDULINGPRIORITY_ABSOLUTE only if you have thorough understanding of dxgkrnl/graphics priorities and understand repercussions of changing them.

**Priority Values Bits[4:0]** translates to following priority values:

0 : Idle Priority - Forward progress is not guaranteed if higher priorties use most of the accelerator time.\
1 : Normal Priority - Most of the processes use this priority with forward progress guarantee.\
2 -15 : Reserved - \
16-29 : Soft Realtime - Preempts lower priorities and periodically yields to lower priorities to ensure their forward progress.\
30 : Hard Realtime - Used for extremely latency sensitive well bounded workloads. This priority does not yield to lower priorities. \
31 : Internal Use \

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)

[IDXGIDevice::GetGPUThreadPriority](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgidevice-getgputhreadpriority)