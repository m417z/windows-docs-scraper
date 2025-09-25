# ASSOCIATIONELEMENT structure

## Description

Defines information used by [AssocCreateForClasses](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-assoccreateforclasses) to retrieve an [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface for a given file association.

## Members

### `ac`

Type: **ASSOCCLASS**

Where to obtain association data and the form the data is stored in. One of the following values from the **ASSOCCLASS** enumeration.

#### ASSOCCLASS_APP_KEY

The **hkClass** member provides the full registry path of an application identifier (APPID).

#### ASSOCCLASS_CLSID_KEY

The **hkClass** member provides the full registry path of a CLSID.

#### ASSOCCLASS_CLSID_STR

The **hkClass** member names a CLSID found as
**HKEY_CLASSES_ROOT**\**CLSID**\*pszClass*.

#### ASSOCCLASS_PROGID_KEY

The **hkClass** member provides the full registry path of a ProgID.

#### ASSOCCLASS_SHELL_KEY

The **hkClass** member names a key found as
**HKEY_CLASSES_ROOT**\**SystemFileAssociations**\*hkClass*.

#### ASSOCCLASS_PROGID_STR

The **pszClass** member names a ProgID found as
**HKEY_CLASSES_ROOT**\*pszClass*.

#### ASSOCCLASS_SYSTEM_STR

The **pszClass** member names a key found as
**HKEY_CLASSES_ROOT**\**SystemFileAssociations**\*pszClass*.

#### ASSOCCLASS_APP_STR

The APPID storing the application information is found at
**HKEY_CLASSES_ROOT**\**Applications**\*FileName* where *FileName* is obtained by sending **pszClass** to [PathFindFileName](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathfindfilenamea).

#### ASSOCCLASS_FOLDER

Use the association information for folders stored under
**HKEY_CLASSES_ROOT**\**Folder**. When this flag is set, **hkClass** and **pszClass** are ignored.

#### ASSOCCLASS_STAR

Use the association information stored under the
**HKEY_CLASSES_ROOT**\***** subkey. When this flag is set, **hkClass** and **pszClass** are ignored.

#### ASSOCCLASS_FIXED_PROGID_STR

**Introduced in Windows 8**. Do not use the user defaults to apply the mapping of the class specified by the **pszClass** member.

#### ASSOCCLASS_PROTOCOL_STR

**Introduced in Windows 8**. Use the user defaults to apply the mapping of the class specified by the **pszClass** member; the class is a protocol.

### `hkClass`

Type: **HKEY**

A registry key that specifies a class that contains association information.

### `pszClass`

Type: **PCWSTR**

A pointer to the name of a class that contains association information.

## See also

[Programmatic Identifiers](https://learn.microsoft.com/windows/desktop/shell/fa-progids)