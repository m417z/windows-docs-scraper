# FsRtlDeregisterUncProvider function

## Description

The **FsRtlDeregisterUncProvider** routine deregisters a redirector that was registered as a Universal Naming Convention (UNC) provider with the multiple UNC provider (MUP).

## Parameters

### `Handle` [in]

MUP handle returned by [FsRtlRegisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncprovider) or [FsRtlRegisterUncProviderEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncproviderex).

## Remarks

To register a UNC provider on Windows Server 2003, Windows XP, or Windows 2000, use [FsRtlRegisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncprovider).

To register a UNC provider on Windows Vista, use [FsRtlRegisterUncProviderEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncproviderex).

For more information, see the following sections in the Design Guide:

[Support for UNC Naming and MUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/support-for-unc-naming-and-mup)

[MUP Changes in Microsoft Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ifs/mup-changes-in-microsoft-windows-vista)

## See also

[FsRtlRegisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncprovider)

[FsRtlRegisterUncProviderEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncproviderex)