# IDsAdminNewObjExt::SetObject

## Description

The **IDsAdminNewObjExt::SetObject** method provides the object creation extension with a pointer to the directory object created.

## Parameters

### `pADsObj` [in]

Pointer to an [IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) interface for the object. This parameter may be **NULL**. If this object is to be kept beyond the scope of this method, the reference count must be incremented by calling [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) or [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

## Return value

The method should always return **S_OK**.

## See also

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IDsAdminNewObjExt](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjext)

[IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref)

[IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q))