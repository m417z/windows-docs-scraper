# IVdsAsync::QueryStatus

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns when the
asynchronous operation is in progress, or has either finished successfully or failed.

## Parameters

### `pHrResult` [out]

The address of an **HRESULT** for the asynchronous operation passed in by the
caller. If the operation is in progress, the value is **VDS_E_OPERATION_PENDING**. If the
operation has finished, the value is the returned **HRESULT** of the operation.

### `pulPercentCompleted` [out]

The address of a **ULONG** passed in by the caller, representing the status of the
asynchronous operation, given as a percentage. If the operation is in progress, the value is between 0 and 99.
If the operation has finished, the value is 100. If the progress of the operation cannot be estimated, the value
is 0.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The operation is in progress or has completed. |
| **VDS_E_OPERATION_PENDING**<br><br>0x80042409L | The operation is in progress. |

## Remarks

The **QueryStatus** method does not wait for
the operation to complete before returning.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)