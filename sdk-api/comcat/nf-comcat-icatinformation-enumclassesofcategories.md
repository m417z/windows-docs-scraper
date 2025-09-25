# ICatInformation::EnumClassesOfCategories

## Description

Retrieves an enumerator for the classes that implement one or more specified category identifiers.

## Parameters

### `cImplemented` [in]

The number of category IDs in the *rgcatidImpl* array. This value cannot be zero. If this value is -1, classes are included in the enumeration, regardless of the categories they implement.

### `rgcatidImpl` [in]

An array of category identifiers.

If a class requires a category identifier that is not specified, it is not included in the enumeration.

### `cRequired` [in]

The number of category IDs in the *rgcatidReq* array. This value can be zero. If this value is -1, classes are included in the enumeration, regardless of the categories they require.

### `rgcatidReq` [in]

An array of category identifiers.

### `ppenumClsid` [out]

A pointer to an [IEnumCLSID](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd542667(v=vs.85)) interface pointer that can be used to enumerate the CLSIDs of the classes that implement the specified category.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## See also

[ICatInformation](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatinformation)