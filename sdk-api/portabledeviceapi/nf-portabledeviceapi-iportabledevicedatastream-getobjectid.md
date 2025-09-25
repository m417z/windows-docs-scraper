# IPortableDeviceDataStream::GetObjectID

## Description

The **GetObjectID** method retrieves the object ID of the resource that was written to the device. This method is only valid after calling **IStream::Commit** on the data stream.

## Parameters

### `ppszObjectID` [out]

The ID of the object just transferred to the device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |
| **E_OUTOFMEMORY** | Insufficient memory is available. |

## Remarks

An object ID is created after the object is created on the device. Therefore, a new object that is created by calling [IPortableDeviceContent::CreateObjectWithPropertiesAndData](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecontent-createobjectwithpropertiesanddata) will not have an ID assigned until the application calls **Commit** on the data transfer stream.

## See also

[IPortableDeviceDataStream Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicedatastream)