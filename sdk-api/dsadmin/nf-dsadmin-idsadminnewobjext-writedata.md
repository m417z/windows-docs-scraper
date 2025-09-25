# IDsAdminNewObjExt::WriteData

## Description

The **IDsAdminNewObjExt::WriteData** method enables the object creation wizard extension to write its data into an object in Active Directory Domain Services.

## Parameters

### `hWnd` [in]

The window handle used as the parent window for possible error messages.

### `uContext` [in]

Specifies the context in which **WriteData** is called. This will be one of the following values.

#### DSA_NEWOBJ_CTX_PRECOMMIT

**WriteData** is called prior to the new object committed to persistent storage. This is the context during which a secondary object creation extension should write its data.

#### DSA_NEWOBJ_CTX_POSTCOMMIT

**WriteData** is called after the new object has been committed to persistent storage.

#### DSA_NEWOBJ_CTX_CLEANUP

There has been a failure during the write process of the temporary object and the temporary object is recreated.

## Return value

Returns **S_OK** if successful or an OLE-defined error code otherwise.

## Remarks

A pointer to the temporary directory object is supplied to the extension when the [IDsAdminNewObjExt::SetObject](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-setobject) method is called.

A secondary object creation extension should not commit the data set during the **WriteData** method by calling [IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo). The primary object creation extension will commit all of the data for the object when all of the extensions have added their data.

## See also

[IDsAdminNewObjExt](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjext)

[IDsAdminNewObjExt::SetObject](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-setobject)