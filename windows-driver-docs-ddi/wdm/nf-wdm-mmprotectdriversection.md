# MmProtectDriverSection function

## Description

The
**MmProtectDriverSection** read-only protects a section of a loaded driver by using the services provided by the Virtual Secure Mode (VSM).

## Parameters

### `AddressWithinSection` [in]

 A pointer to a valid data section belonging to a driver image. The data section should not be already executable, otherwise the API will fail with STATUS_INVALID_PAGE_PROTECTION.

### `Size` [in]

 This parameter is currently reserved for future usage and should be set to 0.

### `Flags` [in]

 Specify the flags which controls the operation:
MM_PROTECT_DRIVER_SECTION_ALLOW_UNLOAD – Used to specify that the driver can still be unloaded after the section has been protected.

## Return value

**MmProtectDriverSection** returns a NTSTATUS value which indicates the result of the operation:

| Return value | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation has been successfully completed and the driver section has been successfully protected |
| **STATUS_INVALID_DEVICE_STATE** | Virtual Secure Mode (VSM) is currently disabled so the function can’t protect the driver section. |
| **STATUS_INVALID_PARAMETER** | An invalid flags bitmask (or a non-zero size) has been specified. |
| **STATUS_INVALID_PAGE_PROTECTION** | The driver’s section specified by an address contained in it is mapped through an invalid protection (executable sections are not supported) |
| **STATUS_NOT_SUPPORTED** | The specified section belongs to a driver that is not supported by this API (see Remarks). |
| **STATUS_ACCESS_VIOLATION** | The specified section is discardable or contains gaps, which are not backed by any physical memory. This usually happen when a section alignment is larger than a page size. |
| **STATUS_ALREADY_COMMITTED** | The specified section has been already protected. |

## Remarks

The routine protects the physical memory backing the driver’s section using the SLAT table (second level address translation) managed by the VSM. The protected memory will be made read-only for the entire Operating System. 

Note that, after the section has been protected, there is no way to remove the protection. This is by design: the only exception of this rule is when the caller specifies the MM_PROTECT_DRIVER_SECTION_ALLOW_UNLOAD flag. In that case, when the target driver is unloaded, the protected section is released and freed.

Drivers mapped with large pages and session drivers are not supported by the **MmProtectDriverSection** API. Furthermore, callers of this API can’t request to protect a discardable section or a section that contains the IAT (Import Address Table).

Note that if the caller specifies an address that does not belong to any loaded driver image, the system will be crashed with the MEMORY_MANAGEMENT bugcheck (type 0x1100).

Callers of the **MmProtectDriverSection** API should execute at IRQL <= APC_LEVEL.