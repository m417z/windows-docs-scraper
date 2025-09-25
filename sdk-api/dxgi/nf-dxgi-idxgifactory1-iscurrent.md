## Description

Informs an application of the possible need to re-create the factory and re-enumerate adapters.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**FALSE**, if a new adapter is becoming available or the current adapter is going away.
**TRUE**, no adapter changes.

**IsCurrent** returns **FALSE** to inform the calling application to re-enumerate adapters.

## Remarks

This method is not supported by DXGI 1.0, which shipped in Windows Vista and Windows Server 2008. DXGI 1.1 support is required, which is available on
Windows 7, Windows Server 2008 R2, and as an update to Windows Vista with Service Pack 2 (SP2) ([KB 971644](https://support.microsoft.com/topic/application-compatibility-update-for-windows-vista-windows-server-2008-windows-7-and-windows-server-2008-r2-february-2010-3eb7848b-9a76-85fe-98d0-729e3827ea60)) and Windows Server 2008 ([KB 971512](https://support.microsoft.com/kb/971512/)).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1)