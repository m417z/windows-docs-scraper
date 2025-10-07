# VMFloppyDiskImageType enumeration

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Specifies the floppy disk formats.

## Constants

**vmFloppyDiskImage\_Unknown**

Unknown format.

**vmFloppyDiskImage\_LowDensity**

A low density format (720K).

**vmFloppyDiskImage\_HighDensity**

A high density format (1.44MB).

**vmFloppyDiskImage\_DMF**

A distribution media format (1.68Mb).

**vmFloppyDiskImage\_LowDensitySingleSided**

A single-sided low density format.

**vmFloppyDiskImage\_MediumDensity**

A medium density format (1.2MB).

**vmFloppyDiskImage\_HighDensityMSS**

A high-density Multiple Sector Size (MSS), used by eXtended Distribution Format (XDF).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[**IVMVirtualPC::CreateFloppyDiskImage**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualpc-createfloppydiskimage)

[**IVMVirtualPC::GetFloppyDiskImageType**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualpc-getfloppydiskimagetype)

