# IEnumPortableDeviceObjectIDs::Reset

## Description

The **Reset** method resets the enumeration sequence to the beginning.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

There is no guarantee that the same objects will be enumerated after this method is called. This is because objects that were enumerated previously might have been deleted or new objects might have been added.

## See also

[IEnumPortableDeviceObjectIDs Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-ienumportabledeviceobjectids)