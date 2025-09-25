## Description

Updates the destination field of an entry in a migration table. You can specify the destination option and the destination.

## Parameters

### `bstrSource` [in]

The source field of the migration table which is to be updated.

### `pvarDestination` [in, optional]

A pointer to a **VARIANT** structure. You can use the DestinationOptions: opDestinationSameAsSource, opDestinationNone, or opDestinationByRelativeName by passing in a *pvarDestination* with a **vt** member of VT_I4. To explicitly pass in the destination, pass in a *pvarDestination* with a **vt** member of VT_BSTR, and this will set the DestinationOption to opDestinationSet. If you pass in null, UpdateDestination uses the default value for the destination option, opDestinationSameAsSource.

### `ppEntry` [out]

The updated entry.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMMapEntry** object.

### VB

Returns a reference to a **GPMMapEntry** object.

## See also

[IGPMMigrationTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)