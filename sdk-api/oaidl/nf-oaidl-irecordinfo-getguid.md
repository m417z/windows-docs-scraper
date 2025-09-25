# IRecordInfo::GetGuid

## Description

Gets the GUID of the record type.

## Parameters

### `pguid` [out]

The class GUID of the TypeInfo that describes the UDT.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)