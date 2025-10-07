# DSOP_SCOPE_INIT_INFO structure

## Description

The **DSOP_SCOPE_INIT_INFO** structure describes one or more scope types that have the same attributes. A scope type is a type of location, for example a domain, computer, or Global Catalog, from which the user can select objects.
This structure is used with [DSOP_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_init_info) when calling [IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize).

## Members

### `cbSize`

Contains the size, in bytes, of the structure.

### `flType`

Flags that indicate the scope types described by this structure. You can combine multiple scope types if all specified scopes use the same settings. This member can be a combination of the following flags.

#### DSOP_SCOPE_TYPE_TARGET_COMPUTER (0x00000001)

Computer specified by the **pwzTargetComputer** member of the
[DSOP_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_init_info) structure.

If the target computer is an up-level or down-level domain controller, this flag is ignored unless the **DSOP_FLAG_SKIP_TARGET_COMPUTER_DC_CHECK** flag is set in the **flOptions** member of the [DSOP_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_init_info) structure.

#### DSOP_SCOPE_TYPE_UPLEVEL_JOINED_DOMAIN (0x00000002)

An up-level domain to which the target computer is joined. If this flag is set, use the **pwzDcName** member to specify the name of a domain controller in the joined domain.

#### DSOP_SCOPE_TYPE_DOWNLEVEL_JOINED_DOMAIN (0x00000004)

A down-level domain to which the target computer is joined.

#### DSOP_SCOPE_TYPE_ENTERPRISE_DOMAIN (0x00000008)

All domains in the enterprise to which the target computer belongs. If the **DSOP_SCOPE_TYPE_UPLEVEL_JOINED_DOMAIN** scope is specified, then the **DSOP_SCOPE_TYPE_ENTERPRISE_DOMAIN** scope represents all domains in the enterprise except the joined domain.

#### DSOP_SCOPE_TYPE_GLOBAL_CATALOG (0x00000010)

A scope that contains objects from all domains in the enterprise. An enterprise can contain only up-level domains.

#### DSOP_SCOPE_TYPE_EXTERNAL_UPLEVEL_DOMAIN (0x00000020)

All up-level domains external to the enterprise but trusted by the domain to which the target computer is joined.

#### DSOP_SCOPE_TYPE_EXTERNAL_DOWNLEVEL_DOMAIN (0x00000040)

All down-level domains external to the enterprise, but trusted by the domain to which the target computer is joined.

#### DSOP_SCOPE_TYPE_WORKGROUP (0x00000080)

The workgroup to which the target computer is joined. Applies only if the target computer is not joined to a domain.

The only type of object that can be selected from a workgroup is a computer.

#### DSOP_SCOPE_TYPE_USER_ENTERED_UPLEVEL_SCOPE (0x00000100)

Enables the user to enter an up-level scope. If neither of the **DSOP_SCOPE_TYPE_USER_ENTERED_*** types is specified, the dialog box restricts the user to the scopes in the **Look in** drop-down list.

#### DSOP_SCOPE_TYPE_USER_ENTERED_DOWNLEVEL_SCOPE (0x00000200)

Enables the user to enter a down-level scope.

### `flScope`

Flags that indicate the format used to return ADsPath for objects selected from this scope. The **flScope** member can also indicate the initial scope displayed in the **Look in** drop-down list. This member can be a combination of the following flags.

LDAP and Global Catalog (GC) paths can be converted to the WinNT ADsPath Syntax. GC paths can be converted to the LDAP format. WinNT objects having an objectSid attribute can be converted to the LDAP format if you specify the **DSOP_SCOPE_FLAG_WANT_SID_PATH** or **DSOP_SCOPE_FLAG_WANT_PROVIDER_LDAP** flags. No other conversions are legal.

#### DSOP_SCOPE_FLAG_STARTING_SCOPE (0x00000001)

The scope described by this structure is initially selected in the **Look in** drop-down list. Only one scope can specify this flag. If no scope specifies this flag, the initial scope is the first successfully created scope in the array of scopes passed to the
[IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize) method.

#### DSOP_SCOPE_FLAG_WANT_PROVIDER_WINNT (0x00000002)

The ADsPaths are converted to use the WinNT provider. For more information, see [WinNT ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/winnt-adspath).

#### DSOP_SCOPE_FLAG_WANT_PROVIDER_LDAP (0x00000004)

The ADsPaths are converted to use the LDAP provider. For more information, see [LDAP ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/ldap-adspath).

#### DSOP_SCOPE_FLAG_WANT_PROVIDER_GC (0x00000008)

The ADsPaths for objects selected from this scope are converted to use the GC provider.

#### DSOP_SCOPE_FLAG_WANT_SID_PATH (0x00000010)

The ADsPaths having an **objectSid** attribute are converted to the form **LDAP://\<SID=***x***>** where *x* represents the hexadecimal digits of the objectSid attribute value.

#### DSOP_SCOPE_FLAG_WANT_DOWNLEVEL_BUILTIN_PATH (0x00000020)

The ADsPaths for down-level, well-known SID objects are an empty string unless this flag is specified (For example; **DSOP_DOWNLEVEL_FILTER_INTERACTIVE**). If this flag is specified, the paths have the form

**WinNT://NT AUTHORITY/Interactive** or **WinNT://Creator owner**.

#### DSOP_SCOPE_FLAG_DEFAULT_FILTER_USERS (0x00000040)

If the scope filter contains users, select the **Users** check box in the dialog.

#### DSOP_SCOPE_FLAG_DEFAULT_FILTER_GROUPS (0x00000080)

If the scope filter contains groups, select the **Groups** check box in the dialog.

#### DSOP_SCOPE_FLAG_DEFAULT_FILTER_COMPUTERS (0x00000100)

If the scope filter contains computers, select the **Computers** check box in the dialog.

#### DSOP_SCOPE_FLAG_DEFAULT_FILTER_CONTACTS (0x00000200)

If the scope filter contains contacts, select the **Contacts** check box in the dialog.

#### DSOP_SCOPE_FLAG_DEFAULT_FILTER_SERVICE_ACCOUNTS (0x00000400)

If the scope filter contains service accounts, select the **Service Accounts** and **Group Managed Service Accounts** check boxes in the dialog.

#### DSOP_SCOPE_FLAG_DEFAULT_FILTER_PASSWORDSETTINGS_OBJECTS (0x00000800)

If the scope filter contains password setting objects, select the **Password Setting Objects** check box in the dialog.

### `FilterFlags`

Contains a [DSOP_FILTER_FLAGS](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_filter_flags) structure that indicates the types of objects presented to the user for this scope or scopes.

### `pwzDcName`

Pointer to a null-terminated Unicode string that contains the name of a domain controller of the domain to which the target computer is joined. This member is used only if the **flType** member contains the **DSOP_SCOPE_TYPE_UPLEVEL_JOINED_DOMAIN** flag. If that flag is not set, **pwzDcName** must be **NULL**.

This member can be **NULL** even if the **DSOP_SCOPE_TYPE_UPLEVEL_JOINED_DOMAIN** flag is specified, in which case, the dialog box looks up the domain controller. This member enables you to name a specific domain controller in a multimaster domain. For example, an administrative application might make changes on a domain controller in a multimaster domain, and then open the object picker dialog box before the changes have been replicated on the other domain controllers.

### `pwzADsPath`

Reserved; must be **NULL**.

### `hr`

Contains an **HRESULT** value that indicates the status of the specific scope. If the
[IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize) method successfully creates the scope, or scopes, specified by this structure, **hr** contains **S_OK**. Otherwise, **hr** contains an error code.

If [IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize) returns **S_OK**, the **hr** members of all the specified **DSOP_SCOPE_INIT_INFO** structures also contain **S_OK**.

## See also

[DSOP_FILTER_FLAGS](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_filter_flags)

[DSOP_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_init_info)

[Directory Object Picker](https://learn.microsoft.com/windows/desktop/AD/directory-object-picker)

[IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize)