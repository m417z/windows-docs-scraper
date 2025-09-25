# DS_SELECTION structure

## Description

The **DS_SELECTION** structure contains data about an object the user selected from an object picker dialog box. The
[DS_SELECTION_LIST](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-ds_selection_list) structure contains an array of **DS_SELECTION** structures.

## Members

### `pwzName`

Pointer to a null-terminated Unicode string that contains the object's relative distinguished name (RDN).

### `pwzADsPath`

Pointer to a null-terminated Unicode string that contains the object's ADsPath. The format of this string depends on the flags specified in the **flScope** member of the
[DSOP_SCOPE_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_scope_init_info) structure for the scope from which this object was selected.

### `pwzClass`

Pointer to a null-terminated Unicode string that contains the value of the object's objectClass attribute.

### `pwzUPN`

Pointer to a null-terminated Unicode string that contains the object's userPrincipalName attribute value. If the object does not have a userPrincipalName value, **pwzUPN** points to an empty string (L"").

### `pvarFetchedAttributes`

Pointer to an array of
[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structures. Each **VARIANT** contains the value of an attribute of the selected object. The attributes retrieved are determined by the attribute names specified in the **apwzAttributeNames** member of the
[DSOP_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_init_info) structure passed to the
[IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize) method. The order of attributes in the **pvarFetchedAttributes** array corresponds to the order of attribute names specified in the **apwzAttributeNames** array.

The object picker dialog box may not be able to retrieve the requested attributes. If the attribute cannot be retrieved, the **vt** member of the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure contains **VT_EMPTY**.

### `flScopeType`

Contains one, or more, of the **DSOP_SCOPE_TYPE_*** that indicate the type of scope from which this object was selected. For more information, and a list of **DSOP_SCOPE_TYPE_*** flags, see the **flType** member of the
[DSOP_SCOPE_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_scope_init_info) structure.

## See also

[DSOP_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_init_info)

[DSOP_SCOPE_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_scope_init_info)

[DS_SELECTION_LIST](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-ds_selection_list)

[Directory Object Picker](https://learn.microsoft.com/windows/desktop/AD/directory-object-picker)

[IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize)

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)