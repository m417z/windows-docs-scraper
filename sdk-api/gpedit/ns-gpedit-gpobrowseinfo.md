# GPOBROWSEINFO structure

## Description

The
**GPOBROWSEINFO** structure contains information that the
[BrowseForGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-browseforgpo) function uses to initialize a GPO browser dialog box. After the user closes the dialog box, the system returns information about the user's actions in this structure.

## Members

### `dwSize`

Specifies the size of the structure, in bytes.

### `dwFlags`

Specifies dialog box options. This member can be one or more of the following values.

#### GPO_BROWSE_DISABLE_NEW

Disables the ability to create a new GPO on any tab other than the **All** tab.

#### GPO_BROWSE_NOCOMPUTERS

Removes the **Computers** tab.

#### GPO_BROWSE_NODSGPOS

Removes the **Domain/OU** and **Sites** tabs.

#### GPO_BROWSE_OPENBUTTON

Changes the **OK** button to **Open**.

#### GPO_BROWSE_INITTOALL

Initializes the dialog box with focus on the **All** tab.

### `hwndOwner`

Specifies the handle to the parent window. If this member is **NULL**, the dialog box has no owner.

### `lpTitle`

Specifies the title bar text. If this member is **NULL**, the title bar text is **Browse for a Group Policy Object**.

### `lpInitialOU`

Specifies the initial domain or organizational unit.

### `lpDSPath`

Pointer to a buffer that receives the Active Directory path of the GPO.

### `dwDSPathSize`

Specifies the size, in characters, of the **lpDSPath** buffer.

### `lpName`

Pointer to a buffer that receives either the computer name or the friendly (display) name of the GPO. If the user opens or creates a GPO in the **Computers** tab, this member contains the computer name. If the user opens or creates a GPO in the Active Directory, this member contains the friendly name. To determine the GPO type, see the description for the **gpoType** member.

This member can be **NULL**.

### `dwNameSize`

Specifies the size, in characters, of the **lpName** buffer.

### `gpoType`

Receives the GPO type. This member can be one of the following values.

#### GPOTypeLocal

Local

#### GPOTypeRemote

Remote

#### GPOTypeDS

Active Directory

### `gpoHint`

Receives a hint about the Active Directory container to which the GPO might be linked. This member can be one of the following values.

#### GPHintUnknown

No link information is available.

#### GPHintMachine

The object might be linked to a computer (local or remote).

#### GPHintSite

The object might be linked to a site.

#### GPHintDomain

The object might be linked to a domain.

#### GPHintOrganizationalUnit

The object might be linked to an organizational unit.

## See also

[BrowseForGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-browseforgpo)

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)