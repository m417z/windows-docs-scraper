# IVdsPack::ReplaceDisk

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Not supported.

This method is reserved for future use.

## Parameters

### `OldDiskId` [in]

The GUID of the old disk.

### `NewDiskId` [in]

The GUID of the new disk.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer,
which VDS initializes on return. Callers must release the interface. Use this interface to cancel, wait for, or
query the status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The disk replacement completed successfully. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This method is not supported in this release. |

## Remarks

Callers can use this method for media migration (replacing an old disk with a new disk) or when repairing a
fault-tolerant set with a missing or failed member—especially for those providers that do not implement hot sparing.

The new disk must be in the same pack as the old disk and cannot contain data; it can have the wrong
partitioning style. In the event of a successful replacement, the old disk retains the partitioning style but no
valid volumes.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)
interface for this method, regardless of whether the call initiates an asynchronous operation. If your provider
does not implement hot sparing, it must support the failed-member scenario: start synchronizing the exposed
fault-tolerant volume again after the caller invokes the
**ReplaceDisk** method.