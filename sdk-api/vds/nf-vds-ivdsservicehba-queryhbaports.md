# IVdsServiceHba::QueryHbaPorts

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an [IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject) enumeration object containing
a list of the HBA ports known to VDS on the local system.

## Parameters

### `ppEnum` [out]

The address of an [IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject) interface pointer that can be used to enumerate the HBA ports as [HBA port objects](https://learn.microsoft.com/windows/desktop/VDS/startup-and-service-objects). For more information, see [Working with Enumeration Objects](https://learn.microsoft.com/windows/desktop/VDS/working-with-enumeration-objects). Callers must release the interface and each of the HBA port objects when they are no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The enumeration of HBA ports was returned successfully. If the local system has no HBA ports, the enumeration is empty. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the VDS service finishes initializing, the method is blocked until the initialization is complete. If the initialization fails, this error is returned. |

## See also

[IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject)

[IVdsServiceHba](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservicehba)