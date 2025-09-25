# FsRtlRegisterFileSystemFilterCallbacks function

## Description

File system filter drivers and file systems call the **FsRtlRegisterFileSystemFilterCallbacks** routine to register notification callback routines to be invoked when the underlying file system performs certain operations.

## Parameters

### `FilterDriverObject` [in]

A pointer to the driver object for the filter or file system driver.

### `Callbacks` [in]

Pointer to a [**FS_FILTER_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_filter_callbacks) structure that contains the entry points of caller-supplied notification callback routines. All of the callback entry points are optional and can be set to **NULL**.

## Return value

The **FsRtlRegisterFileSystemFilterCallbacks** routine can return one of the following status values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The callback routines were successfully registered. |
| STATUS_INSUFFICIENT_RESOURCES | **FsRtlRegisterFileSystemFilterCallbacks** encountered a pool allocation failure when allocating memory to store the callback information. |
| STATUS_FSFILTER_OP_COMPLETED_SUCCESSFULLY | **FsRtlRegisterFileSystemFilterCallbacks** successfully completed an FsFilter operation. |
| STATUS_FILE_LOCKED_WITH_ONLY_READERS | The file was locked and all users of the file can only read. |
| STATUS_FILE_LOCKED_WITH_WRITERS | The file was locked and at least one user of the file can write |
| STATUS_INVALID_PARAMETER | One of the parameters is invalid. |

## Remarks

File system and file system filter drivers should call **FsRtlRegisterFileSystemFilterCallbacks** from the driver's **DriverEntry** routine.

**FsRtlRegisterFileSystemFilterCallbacks** registers the notification callback routines that were specified in the **Callbacks** parameter to be invoked when requests for certain file operations are sent to the underlying file system.

File systems call **FsRtlRegisterFileSystemFilterCallbacks** to set the **PreAcquireForSectionSynchronization** callback member of the [**FS_FILTER_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_filter_callbacks) structure instead of using the obsolete **AcquireFileForNtCreateSection**.

The callback routines registered by **FsRtlRegisterFileSystemFilterCallbacks** supersede the following fast I/O callback routines, which are obsolete and should not be used by file system filter drivers:

* **AcquireForCcFlush**
* **AcquireFileForNtCreateSection**
* **AcquireForModWrite**
* **ReleaseForCcFlush**
* **ReleaseFileForNtCreateSection**
* **ReleaseForModWrite**

## See also

[**FS_FILTER_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_filter_callbacks)