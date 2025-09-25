# IPortableDeviceValuesCollection::GetCount

## Description

Retrieves the number of items in the collection.

## Parameters

### `pcElems` [in]

Pointer to a **DWORD** that contains the number of **IPortableDeviceValues** interfaces in the collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |

## Remarks

None.

## See also

[IPortableDeviceValuesCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevaluescollection)