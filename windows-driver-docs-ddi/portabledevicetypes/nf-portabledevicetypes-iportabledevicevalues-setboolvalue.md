# IPortableDeviceValues::SetBoolValue

## Description

Adds a new **Boolean** value (type VT_BOOL) or overwrites an existing one.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** that specifies the item to create or overwrite.

### `Value` [in]

A **BOOL** that specifies the new value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If an existing value has the same key specified by the *key* parameter, it overwrites the existing value without any warning. The existing key memory is released appropriately.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::GetBoolValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-getboolvalue)