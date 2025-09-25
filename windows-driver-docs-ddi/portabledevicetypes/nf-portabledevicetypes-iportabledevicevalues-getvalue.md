# IPortableDeviceValues::GetValue

## Description

The GetValue interface retrieves a **PROPVARIANT** value that is specified by a key.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** key that specifies the item to retrieve.

### `pValue` [out]

A pointer to the retrieved **PROPVARIANT** value. The caller must release the memory by calling **PropVariantClear** when the call is complete.

## Return value

The method returns an **HRESULT**. Possible return values are shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The property that is specified by *key* is not in the collection. |

## Remarks

This method can be used to retrieve a value of any type from the collection. However, if you know the value type in advance, use one of the specialized retrieval methods of this interface for additional type checking.

When the VARTYPE for *pValue* is VT_VECTOR or VT_UI1, retrieving a **NULL** or zero-sized buffer is not supported. For example, neither pValue.caub.pElems = **NULL** nor pValue.caub.cElems = 0 are allowed.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::RemoveValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-removevalue)

[IPortableDeviceValues::SetValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-setvalue)