# IPortableDevicePropVariantCollection::Clear

## Description

Removes or frees all items in the collection. The collection is considered empty after calling this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

After calling **Clear** the collection is considered type-less, meaning that the **VARTYPE** it was previously set to is no longer restricting **Add** operations. A call to **Add** after calling **Clear** is considered the "first" **Add** for this collection.

## See also

[IPortableDevicePropVariantCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicepropvariantcollection)