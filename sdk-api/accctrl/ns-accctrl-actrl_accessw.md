# ACTRL_ACCESSW structure

## Description

Contains an array of access-control lists for an object and its properties.

## Members

### `cEntries`

The number of entries in the **pPropertyAccessList** array.

### `pPropertyAccessList`

An array of [ACTRL_PROPERTY_ENTRY](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_property_entrya) structures. Each structure contains a list of access-control entries for an object or a specified property on the object.

### `pPropertyAccessList.size_is`

### `pPropertyAccessList.size_is.cEntries`

## Remarks

Note the following type definition.

``` syntax
typedef PACTRL_ACCESSW PACTRL_ACCESSW_ALLOCATE_ALL_NODES;
```

> [!NOTE]
> The accctrl.h header defines ACTRL_ACCESS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IAccessControl::GrantAccessRights](https://learn.microsoft.com/windows/desktop/api/iaccess/nf-iaccess-iaccesscontrol-grantaccessrights)