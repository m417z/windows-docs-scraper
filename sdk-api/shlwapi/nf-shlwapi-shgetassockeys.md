# SHGetAssocKeys function

## Description

Retrieves an array of class subkeys associated with an [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) object.

## Parameters

### `pqa` [in]

A [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface pointer to the object you're interested in.

### `rgKeys` [out]

A pointer to an array of **HKEY** elements that, when this function returns successfully, receives the retrieved class subkeys.

### `cKeys`

The number of elements in the *rgKeys* array. If you are interested in only the primary class subkey, set this value to 1.

## Return value

The number of subkeys inserted into the array.