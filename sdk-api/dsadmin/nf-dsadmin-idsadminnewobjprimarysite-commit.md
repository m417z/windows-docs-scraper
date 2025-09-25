# IDsAdminNewObjPrimarySite::Commit

## Description

The **IDsAdminNewObjPrimarySite::Commit** method causes a single-page primary object creation extension's [IDsAdminNewObjExt::WriteData](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-writedata) method to be called and writes the temporary object to persistent memory.

## Return value

Returns **S_OK** if successful or an OLE-defined error code otherwise. This method fails if the calling extension is not a primary object creation extension. This method also fails if the object creation wizard contains more than one page.

## Remarks

The [IDsAdminNewObjPrimarySite::CreateNew](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjprimarysite-createnew) method must be called before **IDsAdminNewObjPrimarySite::Commit** is called.

When an object creation wizard contains more than one page, the system implements a "Finish" page that displays a summary of the object data to be saved. The system-implemented "Finish" page will perform the **IDsAdminNewObjPrimarySite::Commit** operation. If, however, the object creation wizard only contains one page, the page will have **OK** and **Cancel** command buttons instead of the **Back**, **Next** and **Cancel** buttons normally found in a wizard and no "Finish" page is provided. Because of this, a single-page object creation extension wizard must call **Commit**.

## See also

[IDsAdminNewObjExt::WriteData](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-writedata)

[IDsAdminNewObjPrimarySite](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjprimarysite)

[IDsAdminNewObjPrimarySite::CreateNew](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjprimarysite-createnew)