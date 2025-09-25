# IContactPropertyCollection::GetPropertyType

## Description

Retrieves the type for the current property in the enumeration.

## Parameters

### `pdwType` [in, out]

Type: **DWORD***

Specifies the type of property.

| Value | Meaning |
| --- | --- |
| **CGD_UNKNOWN_PROPERTY**<br><br>0x00000000 |  |
| **CGD_STRING_PROPERTY**<br><br>0x00000001 |  |
| **CGD_DATE_PROPERTY**<br><br>0x00000002 |  |
| **CGD_BINARY_PROPERTY**<br><br>0x00000004 |  |
| **CGD_ARRAY_NODE**<br><br>0x00000008 |  |

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Query is successful. |