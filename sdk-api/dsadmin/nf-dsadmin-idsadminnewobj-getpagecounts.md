# IDsAdminNewObj::GetPageCounts

## Description

The **IDsAdminNewObj::GetPageCounts** method obtains the total number of pages in the wizard as well as the index of the first page of the extension.

## Parameters

### `pnTotal` [out]

Pointer to a **LONG** value that receives the total number of pages contained in the wizard.

### `pnStartIndex` [out]

Pointer to a **LONG** value that receives the zero-based index of the first page of the extension.

## Return value

This method can return one of these values.

Returns one of the following values.

## Remarks

This function will provide results based on the count of pages added using
[IDsAdminNewObjExt::AddPages](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-addpages). If there are changes to the number of pages because of page manipulations by Win32 APIs, the supplied values may not be accurate. If this method is called in response to the [IDsAdminNewObjExt::SetObject](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-setobject) method, the supplied page counts are most likely to be accurate.

## See also

[IDsAdminNewObj](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobj)

[IDsAdminNewObjExt::AddPages](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-addpages)

[IDsAdminNewObjExt::SetObject](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-setobject)