# IEnumVdsObject::Clone

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates an enumeration
with the same state as the current enumeration.

## Parameters

### `ppEnum` [out]

The address of an [IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject) pointer, which
VDS initializes on return. Callers must release the interface.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The new enumeration has been created. |

## Remarks

This method enables you to record a point in an enumeration and return to that point later. When the new,
cloned enumeration is returned, it is at the same point in the enumeration sequence as the original. Henceforth,
however, the clone and the original enumeration operate independently.

## See also

[IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject)