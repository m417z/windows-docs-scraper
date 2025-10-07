# D3DX10DebugMute function

Enable or disable debug messages.

## Parameters

*Mute* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Set to **TRUE** to enable debug messages; set to **FALSE** to disable debug messages.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Use this function to disable error messages for D3DX10 APIs during debug; the use of this function should be guarded by the D3D10\_DEBUG compiler switch.

```
#ifdef D3D10_DEBUG
  BOOL WINAPI D3DX10DebugMute(BOOL Mute);
#endif
```

The default state is **TRUE** for a debug build.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |
| Library<br> | D3DX10.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

