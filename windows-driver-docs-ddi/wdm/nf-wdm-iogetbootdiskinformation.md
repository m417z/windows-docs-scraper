# IoGetBootDiskInformation function

## Description

The **IoGetBootDiskInformation** routine returns information describing the boot and system disks.

## Parameters

### `BootDiskInformation` [in, out]

Pointer to a caller-allocated buffer that the routine uses to return information about the boot and system disks. The routine fills this buffer in with either a [BOOTDISK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bootdisk_information) or a [BOOTDISK_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bootdisk_information_ex) structure.

### `Size` [in]

Specifies the size, in bytes, of the buffer specified by *BootDiskInformation*. Should be either **sizeof**(**BOOTDISK_INFORMATION**) or **sizeof**(**BOOTDISK_INFORMATION_EX**).

## Return value

**IoGetBootDiskInformation** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The routine successfully returned the requested information in the buffer specified by *BootDiskInformation*. |
| **STATUS_INVALID_PARAMETER** | The value of *Size* is less than the size, in bytes, of a **BOOTDISK_INFORMATION** structure. |
| **STATUS_TOO_LATE** | The driver called the routine after the system has already booted. Only boot and system drivers can call **IoGetBootDiskInformation**, and then only in their [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) or [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routines. |

## Remarks

**IoGetBootDiskInformation** can be called only by a boot driver. This driver should call **IoGetBootDiskInformation** in a [Reinitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-driver_reinitialize) callback routine that the driver registers by calling the [IoRegisterBootDriverReinitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdriverreinitialization) routine.

On Windows XP and later versions of Windows, if the *Size* parameter is **sizeof**(**BOOTDISK_INFORMATION_EX**) or larger, the routine returns a [BOOTDISK_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bootdisk_information_ex) structure in the *BootDiskInformation* buffer. Otherwise, if *Size* is at least **sizeof**(**BOOTDISK_INFORMATION**), the routine returns a [BOOTDISK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bootdisk_information) structure.

On Windows 2000, the routine returns only the **BOOTDISK_INFORMATION** structure.

## See also

[BOOTDISK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bootdisk_information)

[BOOTDISK_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bootdisk_information_ex)

[IoRegisterBootDriverReinitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdriverreinitialization)

[Reinitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-driver_reinitialize)