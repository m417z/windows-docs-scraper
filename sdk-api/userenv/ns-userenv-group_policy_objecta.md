# GROUP_POLICY_OBJECTA structure

## Description

The
**GROUP_POLICY_OBJECT** structure provides information about a GPO in a GPO list.

## Members

### `dwOptions`

Specifies link options. This member can be one of the following values.

#### GPO_FLAG_DISABLE

This GPO is disabled.

#### GPO_FLAG_FORCE

Do not override the policy settings in this GPO with policy settings in a subsequent GPO.

### `dwVersion`

Specifies the version number of the GPO.

### `lpDSPath`

Pointer to a string that specifies the path to the directory service portion of the GPO.

### `lpFileSysPath`

Pointer to a string that specifies the path to the file system portion of the GPO.

### `lpDisplayName`

Pointer to the display name of the GPO.

### `szGPOName`

Pointer to a string that specifies a unique name that identifies the GPO.

### `GPOLink`

Specifies the link information for the GPO. This member may be one of the following values.

#### GPLinkUnknown

No link information is available.

#### GPLinkMachine

The GPO is linked to a computer (local or remote).

#### GPLinkSite

The GPO is linked to a site.

#### GPLinkDomain

The GPO is linked to a domain.

#### GPLinkOrganizationalUnit

The GPO is linked to an organizational unit.

### `lParam`

User-supplied data.

### `pNext`

Pointer to the next GPO in the list.

### `pPrev`

Pointer to the previous GPO in the list.

### `lpExtensions`

Extensions that have stored data in this GPO. The format is a string of **GUID**s grouped in brackets. For more information, see the following Remarks section.

### `lParam2`

User-supplied data.

### `lpLink`

Path to the Active Directory site, domain, or organization unit to which this GPO is linked. If the GPO is linked to the local GPO, this member is "Local".

## Remarks

Each GPO could contain data that must be processed by multiple snap-in extensions. Therefore, the data in the **lpExtensions** member is organized as a series of **GUID**s that identify the extensions and snap-in extensions. The data format is as follows:

```cpp
[ext_guid1, snap_in_guid1, snap_in_guid2, ...]
[ext_guid2, snap_in_guid3, snap_in_guid4, ...]
```

First, there is an opening bracket, "[", followed by the **GUID** of the extension. Next, you'll find one or more **GUID**s identifying the snap-in extensions that have stored data in the GPO. After the last snap-in **GUID** for an extension, there is a closing bracket, "]". This pattern is repeated for the next extension.

> [!NOTE]
> The userenv.h header defines GROUP_POLICY_OBJECT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FreeGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-freegpolista)

[GetGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getgpolista)

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)