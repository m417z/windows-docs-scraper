# IPortableDevicePropVariantCollection::ChangeType

## Description

Converts all items in the collection to the specified **VARTYPE**.

## Parameters

### `vt` [in]

Specifies the **VARTYPE** to which you want to convert all items in the collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If this method fails, the collection may be left in an intermediate state, with some members converted and some not converted.

## See also

[IPortableDevicePropVariantCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicepropvariantcollection)