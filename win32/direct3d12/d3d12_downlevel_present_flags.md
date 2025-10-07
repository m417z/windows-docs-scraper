# D3D12\_DOWNLEVEL\_PRESENT\_FLAGS enumeration

Flags passed to the [**ID3D12CommandQueueDownlevel::Present**](https://learn.microsoft.com/windows/win32/direct3d12/id3d12commandqueuedownlevel-present) function to modify behavior.

## Constants

**D3D12\_DOWNLEVEL\_PRESENT\_FLAG\_NONE**

No options selected.

**D3D12\_DOWNLEVEL\_PRESENT\_FLAG\_WAIT\_FOR\_VBLANK**

The **Present** operation won't be done until a VSync has occurred since the last time you **Present**ed.

## Requirements

| Requirement | Value |
|--------|------------------|
| Header | d3d12downlevel.h |
| DLL | D3D12.dll (Windows 7 only) |

## See also
* [ID3D12CommandQueueDownlevel](https://learn.microsoft.com/windows/win32/direct3d12/id3d12commandqueuedownlevel)
* [Direct3D 12 On Windows 7 enumerations](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12on7-enumerations)
* [Direct3D 12 on Windows 7 reference (d3d12downlevel.h)](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12on7-reference)
* [Direct3D 12 On Windows 7](https://devblogs.microsoft.com/directx/porting-directx-12-games-to-windows-7/)