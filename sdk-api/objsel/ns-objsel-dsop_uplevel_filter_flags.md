# DSOP_UPLEVEL_FILTER_FLAGS structure

## Description

The **DSOP_UPLEVEL_FILTER_FLAGS** structure contains flags that indicate the filters to use for an up-level scope. An up-level scope is a scope that supports the ADSI LDAP provider. For more information, see
[ADSI LDAP Provider](https://learn.microsoft.com/windows/desktop/ADSI/adsi-ldap-provider). This structure is contained in the [DSOP_FILTER_FLAGS](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_filter_flags) structure when calling [IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize).

## Members

### `flBothModes`

Filter flags to use for an up-level scope, regardless of whether it is a mixed or native mode domain. This member can be a combination of one or more of the following flags.

#### DSOP_FILTER_INCLUDE_ADVANCED_VIEW (1 (0x1))

Includes objects that have the [showInAdvancedViewOnly](https://learn.microsoft.com/windows/desktop/ADSchema/a-showinadvancedviewonly) attribute set to **TRUE**.

#### DSOP_FILTER_USERS (2 (0x2))

Includes [user](https://learn.microsoft.com/previous-versions/windows/desktop/winmessenger/im-imsgrsession-user-property) objects.

#### DSOP_FILTER_BUILTIN_GROUPS (4 (0x4))

Includes built-in [group](https://learn.microsoft.com/previous-versions/windows/desktop/axe/group) objects. Built-in groups are group objects with a [groupType](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-grouptype) value that contain the **GROUP_TYPE_BUILTIN_LOCAL_GROUP** (0x00000001), **GROUP_TYPE_RESOURCE_GROUP** (0x00000004), and **GROUP_TYPE_SECURITY_ENABLED** (0x80000000) flags.

#### DSOP_FILTER_WELL_KNOWN_PRINCIPALS (8 (0x8))

Includes the contents of the Well Known Security Principals container.

#### DSOP_FILTER_UNIVERSAL_GROUPS_DL (16 (0x10))

Includes distribution [group](https://learn.microsoft.com/previous-versions/windows/desktop/axe/group) objects with universal scope.

#### DSOP_FILTER_UNIVERSAL_GROUPS_SE (32 (0x20))

Includes security groups with universal scope. This flag has no effect in a mixed mode domain because universal security groups do not exist in mixed mode domains.

#### DSOP_FILTER_GLOBAL_GROUPS_DL (64 (0x40))

Includes distribution [group](https://learn.microsoft.com/previous-versions/windows/desktop/axe/group) objects with global scope.

#### DSOP_FILTER_GLOBAL_GROUPS_SE (128 (0x80))

Includes security [group](https://learn.microsoft.com/previous-versions/windows/desktop/axe/group) objects with global scope.

#### DSOP_FILTER_DOMAIN_LOCAL_GROUPS_DL (256 (0x100))

Includes distribution [group](https://learn.microsoft.com/previous-versions/windows/desktop/axe/group) objects with domain local scope.

#### DSOP_FILTER_DOMAIN_LOCAL_GROUPS_SE (512 (0x200))

Includes security [group](https://learn.microsoft.com/previous-versions/windows/desktop/axe/group) objects with domain local scope.

#### DSOP_FILTER_CONTACTS (1024 (0x400))

Includes [contact](https://learn.microsoft.com/previous-versions/windows/desktop/wincontacts/-wincontacts-contact) objects.

#### DSOP_FILTER_COMPUTERS (2048 (0x800))

Includes [computer](https://learn.microsoft.com/windows/desktop/properties/computer-bumper) objects.

#### DSOP_FILTER_SERVICE_ACCOUNTS (0x00001000)

Includes managed service account and group managed service account objects.

#### DSOP_FILTER_PASSWORDSETTINGS_OBJECTS (0x00002000)

Includes password settings objects.

### `flMixedModeOnly`

Filter flags to use for an up-level domain in mixed mode. Mixed mode refers to an up-level domain that may have Windows NT 4.0 Backup Domain Controllers present. This member can be a combination of the flags listed in the **flBothModes** flags. The **DSOP_FILTER_UNIVERSAL_GROUPS_SE** flag has no effect in a mixed-mode domain because universal security groups do not exist in mixed mode domains.

### `flNativeModeOnly`

Filter flags to use for an up-level domain in native mode. Native mode refers to an up-level domain in which an administrator has enabled native mode operation. This member can be a combination of the flags listed in the **flBothModes** flags.

## Remarks

For more information about domain modes, see [Detecting the Operation Mode of a Domain](https://learn.microsoft.com/windows/desktop/AD/detecting-the-operation-mode-of-a-domain).

For more information about group types and scope, see [Group Objects](https://learn.microsoft.com/windows/desktop/AD/group-objects).

## See also

[ADSI LDAP Provider](https://learn.microsoft.com/windows/desktop/ADSI/adsi-ldap-provider)

[DSOP_FILTER_FLAGS](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_filter_flags)

[Directory Object Picker](https://learn.microsoft.com/windows/desktop/AD/directory-object-picker)