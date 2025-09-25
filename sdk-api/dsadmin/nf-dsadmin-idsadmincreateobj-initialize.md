# IDsAdminCreateObj::Initialize

## Description

The **IDsAdminCreateObj::Initialize** method initializes an
[IDsAdminCreateObj](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadmincreateobj) object with data about the container where the object will be created, the class of the object to be created and, possibly, the source object to copy from.

## Parameters

### `pADsContainerObj` [in]

Pointer to an [IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer) interface that represents the container where the object will be created. This parameter must not be **NULL**.

### `pADsCopySource` [in]

Pointer to the [IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) interface of the object from which a copy is made. If the new object is not copied from another object, this parameter is **NULL**. The copy operation is only supported for user objects.

### `lpszClassName` [in]

Pointer to a **WCHAR** string that contains the LDAP name of the object class to be created. This parameter must not be **NULL**. Supported values are: "user", "computer", "printQueue", "group" and "contact".

## Return value

If the method succeeds,
**S_OK** is returned. If the method fails, an OLE-defined error code is returned.

## Remarks

The **IDsAdminCreateObj::Initialize** method must be called before [IDsAdminCreateObj::CreateModal](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadmincreateobj-createmodal) can be called.

## See also

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IDsAdminCreateObj](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadmincreateobj)

[IDsAdminCreateObj::CreateModal](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadmincreateobj-createmodal)