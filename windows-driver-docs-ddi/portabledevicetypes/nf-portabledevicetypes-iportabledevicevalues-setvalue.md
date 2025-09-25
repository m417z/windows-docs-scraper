# IPortableDeviceValues::SetValue

## Description

Adds a new value or overwrites an existing one.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** that specifies the item to create or overwrite.

### `pValue` [in]

A **PROPVARIANT** that specifies the new value. The SDK copies the value, so the caller can release the local variable by calling **PropVariantClear** after calling this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When the VARTYPE for *pValue* is VT_VECTOR or VT_UI1, setting a **NULL** or zero-sized buffer is not supported. For example, neither pValue.caub.pElems = **NULL** nor pValue.caub.cElems = 0 are allowed.

This method can be used to retrieve a value of any type from the collection. However, if you know the value type in advance, use one of the specialized **Set**... methods of this interface to avoid the overhead of working with **PROPVARIANT**s directly

If an existing value has the same key that is specified by the *key* parameter, it overwrites the existing value without any warning. The existing key memory is released appropriately.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::GetValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-getvalue)

[IPortableDeviceValues::RemoveValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-removevalue)