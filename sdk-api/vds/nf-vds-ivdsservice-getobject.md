# IVdsService::GetObject

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an object pointer
for the identified object.

## Parameters

### `ObjectId` [in]

The GUID of the desired object.

### `type` [in]

A [VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type) enumeration value that specifies the object type.
**VDS_OT_UNKNOWN**, **VDS_OT_PROVIDER**,
**VDS_OT_ASYNC**, **VDS_OT_ENUM**, and **VDS_OT_OPEN_VDISK** are not supported.

### `ppObjectUnk` [out]

A pointer to a buffer that receives the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer to the object. When the pointer is no longer needed, the caller should release it by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | An object with the specified identifier and type is not found. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |

## Remarks

VDS notifications return an object identifier instead of an object pointer. Callers use this method to get a
pointer to the object referenced in the notification.

## See also

[IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice)

[VDS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_object_type)