# IPortableDeviceValues::SetUnsignedIntegerValue

## Description

Adds a new **ULONG** value (type VT_UI4) or overwrites an existing one.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** that specifies the item to create or overwrite.

### `Value` [in]

A **ULONG** that specifies the new value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If an existing value has the same key that is specified by the *key* parameter, it overwrites the existing value without any warning.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::GetUnsignedIntegerValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-getunsignedintegervalue)