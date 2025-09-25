# IVdsService::SetFlags

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets service object flags.

## Parameters

### `ulFlags` [in]

The flags enumerated by [VDS_SERVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_service_flag). Callers can set the **VDS_SVF_AUTO_MOUNT_OFF** flag.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The flags were set successfully. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |

## Remarks

Beginning with Windows 8 and Windows Server 2012, the **VDS_SVF_AUTO_MOUNT_OFF** is deprecated. Instead, use the [VDS_SAN_POLICY](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_san_policy) enumeration to control default disk mounting behavior.

## See also

[IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice)

[VDS_SERVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_service_flag)