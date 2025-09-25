# IPortableDevicePropVariantCollection::Add

## Description

Adds an item to the collection.

## Parameters

### `pValue` [in]

Pointer to a new **PROPVARIANT** object to add to the collection. This method copies the **PROPVARIANT** to the collection. You can release your local copy of the variable by calling **PropVariantClear** after calling this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When the VARTYPE for *pValue* is VT_VECTOR or VT_UI1, setting and retrieving a **NULL** or zero-sized buffer is not supported. For example, neither pValue.caub.pElems = **NULL** nor pValue.caub.cElems = 0 are allowed.

If a caller tries to add an item of a different **VARTYPE** contained in the collection and the **PROPVARIANT** value cannot be changed by this interface automatically, this method will fail. To change the collection type manually, call [IPortableDevicePropVariantCollection::ChangeType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicepropvariantcollection-changetype).

## See also

[IPortableDevicePropVariantCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicepropvariantcollection)