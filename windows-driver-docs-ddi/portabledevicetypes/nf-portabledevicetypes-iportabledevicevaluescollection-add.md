# IPortableDeviceValuesCollection::Add

## Description

Adds an item to the collection.

## Parameters

### `pValues` [in]

Pointer to an **IPortableDeviceValues** interface to add to the collection. The interface is not actually copied, but **AddRef** is called on it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to add the value to the collection. |

## Remarks

None.

## See also

[IPortableDeviceValuesCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevaluescollection)