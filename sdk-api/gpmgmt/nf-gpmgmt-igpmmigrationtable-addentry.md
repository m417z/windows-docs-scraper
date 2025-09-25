## Description

Creates an entry in the migration table. The method updates an existing entry.

## Parameters

### `bstrSource` [in]

Source field of the entry. This parameter cannot be null.

### `gpmEntryType` [in]

This parameter must be one of the following values.

#### typeUser

This value equals 0 (zero). Creates a User entry in the migration table.

#### typeComputer

Creates an entry for a User.

#### typeLocalGroup

Creates an entry for a LocalGroup.

#### typeGlobalGroup

Creates an entry for a GlobalGroup.

#### typeUniversalGroup

Creates an entry for a UniversalGroup.

#### typeUNCPath

Creates an entry for a UNCPath.

#### typeUnknown

Creates an entry for an unknown.

### `pvarDestination` [in, optional]

A pointer to a **VARIANT** structure. You can use the **DestinationOptions**: **opDestinationSameAsSource**, **opDestinationNone**, or **opDestinationByRelativeName** by passing in a *pvarDestination* with a **vt** member of VT_I4. To explicitly pass in the destination, pass in a *pvarDestination* with a **vt** member of VT_BSTR, and this sets the **DestinationOptions** to **opDestinationSet**. If you pass in null, **AddEntry** uses the default value for the destination option, **opDestinationSameAsSource**.

### `ppEntry` [out]

The new entry.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMMapEntry** object.

### VB

Returns a reference to a **GPMMapEntry** object.

## See also

[IGPMMigrationTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)