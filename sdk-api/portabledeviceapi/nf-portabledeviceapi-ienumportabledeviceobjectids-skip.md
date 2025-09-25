# IEnumPortableDeviceObjectIDs::Skip

## Description

The **Skip** method skips a specified number of objects in the enumeration sequence.

## Parameters

### `cObjects` [in]

The number of objects to skip.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The specified number of objects could not be skipped (for instance, if fewer than *cObjects* remained in the enumeration sequence). |

## See also

[IEnumPortableDeviceObjectIDs](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-ienumportabledeviceobjectids-skip)

[IEnumPortableDeviceObjectIDs Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-ienumportabledeviceobjectids)