# IPortableDevicePropVariantCollection::GetType

## Description

Retrieves the data type of the items in the collection.

## Parameters

### `pvt` [out]

A Platform SDK **VARTYPE** enumeration value that indicates the data type of all the items in the collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |

## Remarks

All items that are stored in an **IPortableDevicePropVariantCollection** are the same type.

## See also

[IPortableDevicePropVariantCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicepropvariantcollection)