# IDsAdminNewObjPrimarySite::CreateNew

## Description

The **IDsAdminNewObjPrimarySite::CreateNew** method enables a primary object creation extension to create a temporary directory service object in Active Directory Domain Services. This object is then passed to each object creation extension in the extension's [IDsAdminNewObjExt::SetObject](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-setobject) method.

## Parameters

### `pszName` [in]

Pointer to a **WCHAR** string that contains the name of the object to be created.

## Return value

If the method
succeeds, **S_OK** is returned. If the method fails, an OLE-defined error code is returned. This method fails if the calling extension is not a primary object creation extension.

## See also

[IDsAdminNewObjExt::SetObject](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-setobject)

[IDsAdminNewObjPrimarySite](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjprimarysite)