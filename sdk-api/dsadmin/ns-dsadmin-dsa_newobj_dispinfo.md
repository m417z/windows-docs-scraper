# DSA_NEWOBJ_DISPINFO structure

## Description

The **DSA_NEWOBJ_DISPINFO** structure is used with the [IDsAdminNewObjExt::Initialize](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-initialize) method to supply additional data about an Active Directory Domain Services object creation wizard.

## Members

### `dwSize`

Contains the size, in bytes, of the structure. This member is used for versioning purposes.

### `hObjClassIcon`

Contains the handle of the class icon for the object created.

### `lpszWizTitle`

Pointer to a null-terminated Unicode string that contains the title of the wizard.

### `lpszContDisplayName`

Pointer to a null-terminated Unicode string that contains the display name, or canonical name, of the container the object is created in.

## See also

[IDsAdminNewObjExt::Initialize](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnewobjext-initialize)