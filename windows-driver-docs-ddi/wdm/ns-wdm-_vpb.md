## Description

The volume parameter block (VPB) structure is used to map a device object that represents a mounted file system volume to a device object that represents a physical or virtual disk device.

## Members

### `Type`

A read-only member that is used by the system to indicate that the structure is a VPB object.

### `Size`

A read-only member that is used by the system to indicate that the structure is a VPB object.

### `Flags`

| Value | Meaning |
|---|---|
| VPB_MOUNTED | This bit is set by the I/O manager to indicate that the file system has mounted the logical volume. |
| VPB_LOCKED | This bit can be set or cleared by the file system driver that has mounted the logical volume. When set, the I/O manager will fail all subsequent create/open requests that are targeted at the logical volume. File systems may choose to set this member in response to application requests to lock the volume, or if they temporarily wish to prevent any create/open request from proceeding. |
| VPB_PERSISTENT | This bit can be set or cleared by file system drivers. If set, the I/O manager will not delete the VPB structure even if **ReferenceCount** is zero. |
| VPB_REMOVE_PENDING | Set by the Plug and Play (PnP) manager to indicate that the underlying device is being removed. |
| VPB_RAW_MOUNT | Indicates that only the RAW file system can be mounted on the device. |
| VPB_DIRECT_WRITES_ALLOWED | Indicates that direct write operations to the volume are allowed. This flag is set either by the I/O manager when the RAW file system is mounted or by the file system itself when it determines that the volume can be safely written to. It is typically safe to write to a volume when the file system is dismounted. |

### `VolumeLabelLength`

A read/write member that specifies the length of the volume label, in bytes. This member must be set by the file system driver. If the volume has no label, this member must be set to zero.

### `DeviceObject`

A read/write member, set by the file system driver, which points to a device object of type **FILE_DEVICE_DISK_FILE_SYSTEM**. This device object is created by the file system driver to represent the mounted volume.

### `RealDevice`

A read-only member, set by the I/O manager, which points to the device object for a physical or virtual disk device that contains the mountable logical volume (pointed to by **DeviceObject**).

### `SerialNumber`

A read/write member that specifies the serial number associated with the file system volume. This member should be set by the file system driver, if available.

### `ReferenceCount`

A read-only member that specifies the reference count for the VPB structure. If the reference count for the VPB structure is greater than zero, the I/O manager does not deallocate the VPB structure. Be aware that **ReferenceCount** can be considered a read/write member when a file system driver must keep the volume present to process a tear down request.

### `VolumeLabel`

A read/write member, set by the file system driver, that specifies the label of the mounted volume. The length of the volume label must be 32 wide-characters or less. Currently **MAXIMUM_VOLUME_LABEL_LENGTH** is defined as follows:

```cpp
#define MAXIMUM_VOLUME_LABEL_LENGTH  (32 * sizeof(WCHAR));
```

## Remarks

A volume parameter block (VPB) object is used to create an association between a physical disk device object and a logical volume device object. That is, a VPB maps a file system's volume device object to the device or partition upon which the volume is mounted. A VPB object exists only for device objects that represent physical media, virtual media, or logical media that can be mounted.

The I/O manager allocates and deallocates memory for the VPB structure from nonpaged pool. This allocation (or deallocation) occurs when a device object (as described previously) is created by calling either the [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) or [IoVerifyVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioverifyvolume) functions. That is, the device object that is created must be one of the following types:

- FILE_DEVICE_DISK

- FILE_DEVICE_CD_ROM

- FILE_DEVICE_TAPE

- FILE_DEVICE_VIRTUAL_DISK

For more information about device object types, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

Drivers must call [IoAcquireVpbSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioacquirevpbspinlock) before they access any applicable members of the VPB object.

Opaque members should be considered inaccessible. Drivers with dependencies on object member locations or access to opaque members might not remain portable and interoperable with other drivers over time.

Drivers can use read-only members to acquire relevant information. Drivers must not modify read-only members or the object that the member points to, if the member is a pointer.

## See also

[**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[How the Volume Is Mounted](https://learn.microsoft.com/windows-hardware/drivers/ifs/how-the-volume-is-mounted)