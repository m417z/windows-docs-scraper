# SafeArrayCreateVectorEx function

## Description

Creates and returns a one-dimensional safe array of the specified VARTYPE and bounds.

## Parameters

### `vt` [in]

The base type of the array (the VARTYPE of each element of the array). The FADF_RECORD flag can be set for VT_RECORD. The FADF_HAVEIID can be set for VT_DISPATCH or VT_UNKNOWN and FADF_HAVEVARTYPE can be set for all other types.

### `lLbound` [in]

The lower bound for the array. This parameter can be negative.

### `cElements` [in]

The number of elements in the array.

### `pvExtra` [in]

The type information of the user-defined type, if you are creating a safe array of user-defined types. If the vt parameter is VT_RECORD, then *pvExtra* will be a pointer to an [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo) describing the record. If the *vt* parameter is VT_DISPATCH or VT_UNKNOWN, then *pvExtra* will contain a pointer to a GUID representing the type of interface being passed to the array.

## Return value

A safe array descriptor, or null if the array could not be created.