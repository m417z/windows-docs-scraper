# IDsAdminNewObjExt::Initialize

## Description

The **IDsAdminNewObjExt::Initialize** method initializes an object creation wizard extension.

## Parameters

### `pADsContainerObj` [in]

Pointer to the [IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer) interface of an existing container where the object are created. This parameter must not be **NULL**. If this object is to be kept beyond the scope of this method, the reference count must be incremented by calling [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) or [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

### `pADsCopySource` [in]

Pointer to the [IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) interface of the object from which a copy is made. If the new object is not copied from another object, this parameter is **NULL**. For more information about copy operations, see the Remarks section. If this object is to be kept beyond the scope of this method, the reference count must be incremented by calling [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) or [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

### `lpszClassName` [in]

Pointer to a **WCHAR** string containing the LDAP name of the object class to be created. This parameter must not be **NULL**. Supported values are: "user", "computer", "printQueue", "group", and "contact".

### `pDsAdminNewObj` [in]

Pointer to an [IDsAdminNewObj](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobj) interface that contains additional data about the wizard. You can also obtain the [IDsAdminNewObjPrimarySite](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjprimarysite) interface of the primary extension by calling [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) with **IID_IDsAdminNewObjPrimarySite** on this interface. If this object is to be kept beyond the scope of this method, the reference count must be incremented by calling [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) or **IUnknown::QueryInterface**.

### `pDispInfo` [in]

Pointer to a [DSA_NEWOBJ_DISPINFO](https://learn.microsoft.com/windows/desktop/api/dsadmin/ns-dsadmin-dsa_newobj_dispinfo) structure that contains additional data about the object creation wizard.

## Return value

Returns **S_OK** if successful or an OLE-defined error code otherwise.

## Remarks

An object in Active Directory Domain Services can either be created from nothing or copied from an existing object. If the new object is created from an existing object, *pADsCopySource* will contain a pointer to the object from which the copy is made. If the new object is not being copied from another object, *pADsCopySource* will be **NULL**. The copy operation is only supported for user objects.

## See also

[DSA_NEWOBJ_DISPINFO](https://learn.microsoft.com/windows/desktop/api/dsadmin/ns-dsadmin-dsa_newobj_dispinfo)

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IDsAdminNewObj](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobj)

[IDsAdminNewObjExt](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjext)

[IDsAdminNewObjPrimarySite](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjprimarysite)

[IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref)

[IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q))