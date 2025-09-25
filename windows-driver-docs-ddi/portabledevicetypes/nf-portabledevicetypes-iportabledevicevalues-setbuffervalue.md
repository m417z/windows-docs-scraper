# IPortableDeviceValues::SetBufferValue

## Description

Adds a new **BYTE*** value (type VT_VECTOR or VT_UI1) or overwrites an existing one.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** that specifies the item to create or overwrite.

### `pValue` [in]

A pointer to a **BYTE** that contains the data to write to the item. The submitted buffer data is copied to the interface, so the caller can free this buffer after making this call.

### `cbValue` [in]

The size of the value pointed to by *pValue*, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Setting a **NULL** or a zero-sized buffer is not supported.

If an existing value has the same key that is specified by the *key* parameter, it overwrites the existing value without any warning. The existing key memory is released appropriately.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::GetBufferValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-getbuffervalue)