# ISensorCollection::GetCount

## Description

Retrieves the count of sensors in the collection.

## Parameters

### `pCount` [out]

Address of a **ULONG** that receives the count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL was passed in for pCount. |

## See also

[ISensorCollection](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorcollection)