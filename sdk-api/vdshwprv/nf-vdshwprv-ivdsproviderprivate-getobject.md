# IVdsProviderPrivate::GetObject

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the specified object.

## Parameters

### `ObjectId` [in]

The GUID of the object.

### `type` [in]

The object type enumerated by [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type).

### `ppObjectUnk` [out]

The address of an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer for the object. When the pointer is no longer needed, the caller should release it by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The object was not found. |

## Remarks

The object can be a subsystem, controller, LUN, LUN plex, drive, pack, disk, volume, or volume plex object. Each object represents a physical device (such as a subsystem, drive, or controllers) or a virtual device (such as a LUN or LUN plex). The hardware provider should create one COM object for each physical or virtual device.

## See also

[IVdsProviderPrivate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsproviderprivate)

[VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type)