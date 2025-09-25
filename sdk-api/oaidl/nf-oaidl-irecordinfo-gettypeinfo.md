# IRecordInfo::GetTypeInfo

## Description

Retrieves the type information that describes a UDT or safearray of UDTs.

## Parameters

### `ppTypeInfo` [out]

The information type of the record.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## Remarks

**AddRef** is called on the pointer *ppTypeInfo*.

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)