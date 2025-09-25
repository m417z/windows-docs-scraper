# IPortableDeviceKeyCollection::Add

## Description

Adds a property key to the collection.

## Parameters

### `Key` [in]

A **REFPROPERTYKEY** to add to the collection. This method copies the key to the collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to add the key to the collection. |

## Remarks

None.

## See also

[IPortableDeviceKeyCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicekeycollection)