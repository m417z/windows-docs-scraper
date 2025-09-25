# IPortableDeviceContent::CreateObjectWithPropertiesAndData

## Description

The **CreateObjectWithPropertiesAndData** method creates an object with both properties and data on the device.

## Parameters

### `pValues`

An **IPortableDeviceValues** collection of properties to assign to the object. For a list of required and optional properties for an object, see [Requirements for Objects](https://learn.microsoft.com/windows/desktop/wpd_sdk/requirements-for-objects).

### `ppData` [out]

Address of a variable that receives a pointer to an **IStream** interface that the application uses to send the object data to the device. The object will not be created on the device until the application sends the data by calling *ppData*->**Commit**. To abandon a data transfer in progress, you can call *ppData* -> **Revert**. The caller must release this interface when it is done with it. The underlying object extends both **IStream** and [IPortableDeviceDataStream](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicedatastream).

### `pdwOptimalWriteBufferSize` [in, out]

An optional **DWORD** pointer that specifies the optimal buffer size for the application to use when writing the data to *ppData*. The application can specify **TRUE** to ignore this.

### `ppszCookie` [in, out]

An optional unique, null-terminated string ID that is used to identify this creation request in the application's implementation of [IPortableDeviceEventCallback](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceeventcallback) (if implemented). When the device finishes creating the object, it will send this identifier to the callback function. This identifier allows an application to monitor object creation in a different thread from the one that called [CreateObjectWithPropertiesOnly](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecontent-createobjectwithpropertiesonly). The SDK allocates this memory, and the caller must release it using **CoTaskMemFree**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## Remarks

Some objects are only a collection of properties—such as a folder, which is only a collection of pointers to other objects—while other objects are both properties and data—such as an audio file, which contains all the properties and the actual music bits. This method is used to create an object that requires both properties and data. To create a properties-only object, call [CreateObjectWithPropertiesOnly](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecontent-createobjectwithpropertiesonly).

Because the object is not created until the application calls **Commit** on the retrieved **IStream** *ppData*, the object will not have an ID until **Commit** is called on it. **Commit** is synchronous, so when that method returns successfully, the object will exist on the device.

After calling **Commit** to create the object, call **QueryInterface** on *ppData* for [IPortableDeviceDataStream](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicedatastream), and then call [IPortableDeviceDataStream::GetObjectID](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicedatastream-getobjectid) to get the ID of the newly created object.

#### Examples

For an example of how to use this method, see [Transferring an Image or Music File to the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/transferring-an-image-or-music-file-to-the-device).

## See also

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)

[IPortableDeviceDataStream Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicedatastream)

[Transferring an Image or Music File to the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/transferring-an-image-or-music-file-to-the-device)