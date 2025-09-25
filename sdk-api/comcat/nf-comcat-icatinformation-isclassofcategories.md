# ICatInformation::IsClassOfCategories

## Description

Determines whether a class implements one or more categories.

## Parameters

### `rclsid` [in]

The class identifier.

### `cImplemented` [in]

The number of category IDs in the *rgcatidImpl* array. This value cannot be zero. If this value is -1, the implemented categories are not tested.

### `rgcatidImpl` [in]

An array of category identifiers.

If the class requires a category not listed in *rgcatidReq*, it is not included in the enumeration.

### `cRequired` [in]

The number of category IDs in the *rgcatidReq* array. This value can be zero. If this value is -1, the required categories are not tested.

### `rgcatidReq` [in]

An array of category identifiers.

## Return value

If the class ID is of one of the specified categories, the return value is S_OK. Otherwise, is it S_FALSE.

## See also

[ICatInformation](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatinformation)