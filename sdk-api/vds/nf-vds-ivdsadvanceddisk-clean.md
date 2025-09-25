# IVdsAdvancedDisk::Clean

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Removes partition information
and uninitializes basic or dynamic disks.

**Windows Server 2003:** The **Clean** method is not supported for removable devices.

## Parameters

### `bForce` [in]

If **TRUE**, cleans a disk containing data volumes or ESP partitions.

### `bForceOEM` [in]

If **TRUE**, cleans a MBR-based disk containing the known OEM partitions in the following table or cleans a
GPT-based disk containing any OEM partition. An OEM partition has the GPT_ATTRIBUTE_PLATFORM_REQUIRED flag set
on a GPT-based disk.

| Partition type | Description |
| --- | --- |
| 0x12 | An EISA partition. |
| 0x84 | A hibernation partition for laptops. |
| 0xA0 | A diagnostic partition for some HP laptops. |
| 0xDE | A partition defined by Dell. |
| 0xFE | An IBM IML partition. |

### `bFullClean` [in]

If **TRUE**, cleans the entire disk by replacing the data on each sector with zeros; otherwise, this method cleans
only the first and the last megabytes on the disk.

### `ppAsync` [out]

The address of a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface
pointer, which VDS initializes on return. Callers must release the interface. Use this pointer to cancel, wait
for, or query the status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The data was removed successfully and the disk was uninitialized. |
| **VDS_E_NO_MEDIA**<br><br>0x80042412L | There is no media in the removable device. |
| **VDS_E_MISSING_DISK**<br><br>0x80042454L | The disk is missing. |
| **VDS_E_OPERATION_DENIED**<br><br>0x8004240AL | The operation failed under one of the following conditions:<br><br>* The disk contains an OEM partition and *bForceOEM* is false.<br>* The disk contains a volume or ESP partition and *bForce* is **FALSE**.<br>* The disk contains one of the system volumes regardless of whether *bForce* is **TRUE**   or **FALSE**. A system volume can be any of the following items:   + A volume containing the operating system loader.   + A boot volume, which contains the system32 directory.   + A volume containing the pagefile or hibernation file, or a volume used as a crash dump.   + An ESP partition (the partition from which the system boots). |
| **VDS_S_DISK_PARTIALLY_CLEANED**<br><br>0x0004241AL | The partition table is cleaned, but not all sectors are cleaned during a full clean. Alternatively, some sectors of the first megabyte and the last megabyte are cleaned; however, unless the clean is a full clean, the remaining sectors are not cleaned. |

## Remarks

Before calling this method, the caller should dismount any mounted volumes on the disk by calling [IVdsVolumeMF::Dismount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-dismount) for each volume.

Use the *bForce* parameter, the *bForceOEM* parameter, or both
with this method unless you first delete all data volumes, known OEM partitions, and ESP partitions on the disk.
This requirement excludes metadata partitions such as the MSR, the LDM metadata partition, and unknown OEM partitions.

**Windows Server 2003:** The **Clean** method is not supported for removable devices.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface for
this method, regardless of whether the call initiates an asynchronous operation.

## See also

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)