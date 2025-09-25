## Description

The **WHEA_ERROR_RECORD_HEADER_VALIDBITS** union describes which members of a [**WHEA_ERROR_RECORD_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header) structure contain valid data.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.PlatformId`

A single bit that indicates that the **PlatformId** member of the **WHEA_ERROR_RECORD_HEADER** structure contains valid data.

### `DUMMYSTRUCTNAME.Timestamp`

A single bit that indicates that the **Timestamp** member of the **WHEA_ERROR_RECORD_HEADER** structure contains valid data.

### `DUMMYSTRUCTNAME.PartitionId`

A single bit that indicates that the **PartitionId** member of the **WHEA_ERROR_RECORD_HEADER** structure contains valid data.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `AsULONG`

A ULONG representation of the contents of the **WHEA_ERROR_RECORD_HEADER_VALIDBITS** union.

## Remarks

A **WHEA_ERROR_RECORD_HEADER_VALIDBITS** union is contained within the [**WHEA_ERROR_RECORD_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header) structure.

After the release of Windows Server 2008, it was discovered that the **Timestamp** and **PlatformId** members of the **WHEA_ERROR_RECORD_HEADER_VALIDBITS** union are defined in the incorrect order. This topic now defines the correct order for these members.

If you build your [Windows hardware error architecture (WHEA) user-mode application](https://learn.microsoft.com/windows-hardware/drivers/whea/windows-hardware-error-architecture-aware-user-mode-applications) or [platform-specific hardware error driver (PSHED) plug-in](https://learn.microsoft.com/windows-hardware/drivers/whea/platform-specific-hardware-error-driver-plug-ins2) with the header files from the Windows Server 2008 version of the WDK or Windows SDK, you will have trouble only if your application or PSHED plug-in accesses the **Timestamp** and **PlatformId** members directly when it processes the contents of a **WHEA_ERROR_RECORD_HEADER** structure. When you test these bits in the **AsULONG** member through the bitfield constants that are described in the following list, you will always produce the correct results.

This problem has been fixed in the Windows 7 version of the WDK and SDK.

## See also

[**WHEA_ERROR_RECORD_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header)