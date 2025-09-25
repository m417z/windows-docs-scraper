# GetRecordInfoFromGuids function

## Description

Returns a pointer to the [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo) interface for a UDT by passing the GUID of the type information without having to load the type library.

## Parameters

### `rGuidTypeLib` [in]

The GUID of the type library containing the UDT.

### `uVerMajor` [in]

The major version number of the type library of the UDT.

### `uVerMinor` [in]

The minor version number of the type library of the UDT.

### `lcid` [in]

The locale ID of the caller.

### `rGuidTypeInfo` [in]

The GUID of the typeinfo that describes the UDT.

### `ppRecInfo` [out]

The [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo) interface.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

A pointer to [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo) can be serialized by writing out the GUIDs and version numbers and deserialized by loading the information and passing it to **GetRecordInfoFromGuids**.