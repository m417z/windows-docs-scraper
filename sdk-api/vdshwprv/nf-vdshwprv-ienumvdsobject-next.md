# IEnumVdsObject::Next

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns a specified number of
objects in the enumeration, beginning from the current point. For more information, see [Working with Enumeration Objects](https://learn.microsoft.com/windows/desktop/VDS/working-with-enumeration-objects).

## Parameters

### `celt` [in]

The number of objects to return.

### `ppObjectArray` [out]

The address of an array of [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointers, which VDS initializes
on return.

### `pcFetched` [out]

The address of a **ULONG**, which VDS initializes on return to the number of
objects in *ppObjectArray*.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method returned the specified number of objects. The number of returned objects reported in *pcFetched* equals *celt*; returns those objects. |
| **S_FALSE** | The specified number of returned objects is greater than the number of objects remaining. All remaining objects are returned, and the number of returned objects is reported in *pcFetched* is less than *celt*; returns those objects. |

## Remarks

To obtain object-specific interface pointers from the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointers returned in the *ppObjectArray* array, use the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method.

## See also

[IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject)