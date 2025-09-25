# IVdsAsync::Cancel

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Cancels the asynchronous
operation.

## Return value

This method can return standard HRESULT values, such as E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | The method is not supported. Neither the basic provider nor the current dynamic provider support this method. |
| **VDS_E_OPERATION_CANCELED**<br><br>0x8004240DL | The operation has already been canceled. |
| **VDS_E_CANCEL_TOO_LATE**<br><br>0x8004240CL | The operation has progressed too far to cancel. |
| **VDS_E_INCOMPATIBLE_FILE_SYSTEM**<br><br>0x80042425L | The file system is incompatible with the specified operation. |
| **VDS_E_INCOMPATIBLE_MEDIA**<br><br>0x80042426L | The media is incompatible with this operation. |
| **VDS_E_ACCESS_DENIED**<br><br>0x80042427L | Access is denied. An application using VDS must run under the Backup Operator or Administrators group account. |

## Remarks

Dynamic providers do not implement this method. The basic provider checks for this method only when cleaning
a disk and does not implement it for any other operation.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)