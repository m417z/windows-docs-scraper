# DSOP_INIT_INFO structure

## Description

The **DSOP_INIT_INFO** structure contains data required to initialize an object picker dialog box. This structure is used with the
[IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize) method.

## Members

### `cbSize`

Contains the size, in bytes, of the structure.

### `pwzTargetComputer`

Pointer to a null-terminated Unicode string that contains the name of the target computer. The dialog box operates as if it is running on the target computer, using the target computer to determine the joined domain and enterprise. If this value is **NULL**, the target computer is the local computer.

### `cDsScopeInfos`

Specifies the number of elements in the **aDsScopeInfos** array.

### `aDsScopeInfos`

Pointer to an array of
[DSOP_SCOPE_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_scope_init_info) structures that describe the scopes from which the user can select objects. This member cannot be **NULL** and the array must contain at least one element because the object picker cannot operate without at least one scope.

### `flOptions`

Flags that determine the object picker options. This member can be zero or a combination of one or more of the following flags.

#### DSOP_FLAG_MULTISELECT (0x00000001)

If this flag is set, the user can select multiple objects. If this flag is not set, the user can select only one object.

#### DSOP_FLAG_SKIP_TARGET_COMPUTER_DC_CHECK (0x00000002)

If this flag is set and the **DSOP_SCOPE_TYPE_TARGET_COMPUTER** flag is set in the **aDsScopeInfos** array, the target computer is always included in the **Look in** drop-down list.

If this flag is not set and the target computer is an up-level or down-level domain controller, the **DSOP_SCOPE_TYPE_TARGET_COMPUTER** flag is ignored and the target computer is not included in the **Look in** drop-down list.

To save time during initialization, this flag should be set if it is known that the target computer is not a domain controller. However, if the target computer is a domain controller, this flag should not be set because it is better for the user to select domain objects from the domain scope rather than from the domain controller itself.

### `cAttributesToFetch`

Contains the number of elements in the **apwzAttributeNames** array. This member can be zero.

### `apwzAttributeNames`

Pointer to an array of null-terminated Unicode strings that contain the names of the attributes to retrieve for each selected object. If **cAttributesToFetch** is zero, this member is ignored.

## See also

[DSOP_SCOPE_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/objsel/ns-objsel-dsop_scope_init_info)

[Directory Object Picker](https://learn.microsoft.com/windows/desktop/AD/directory-object-picker)

[IDsObjectPicker::Initialize](https://learn.microsoft.com/windows/desktop/api/objsel/nf-objsel-idsobjectpicker-initialize)