# IPortableDeviceContent::CreateObjectWithPropertiesOnly

## Description

The **CreateObjectWithPropertiesOnly** method creates an object with only properties on the device.

## Parameters

### `pValues`

An IPortableDeviceValues collection of properties to assign to the object. For a list of required and optional properties for an object, see [Requirements for Objects](https://learn.microsoft.com/windows/desktop/wpd_sdk/requirements-for-objects).

### `ppszObjectID` [in, out]

An optional string pointer to receive the name of the new object. Can be **NULL**, if not needed. Windows Portable Devices defines the constant WPD_DEVICE_OBJECT_ID to represent a device. The SDK allocates this memory; the caller must release it using **CoTaskMemFree**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## Remarks

Some objects are only a collection of properties—such as a folder, which is only a collection of pointers to other objects—while other objects are both properties and data—such as an audio file, which contains all the properties and the actual music bits. This method is used to create an object that contains only properties. To create an object with both properties and data, use [CreateObjectWithPropertiesAndData](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecontent-createobjectwithpropertiesanddata).

This method is synchronous; when it returns, the new object should be present on the device.

The object that the driver actually creates might be a properties-and-data object, depending on what type of object is most convenient for the driver. To check what kind of object the driver has created, request the [WPD_OBJECT_FORMAT](https://learn.microsoft.com/windows/desktop/wpd_sdk/object-properties) property of the new object.

The object will be created on the device when this method returns.

#### Examples

For an example of how to use this method, see [Transferring a Properties-Only Object to the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/transferring-a-properties-only-object-to-the-device).

## See also

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)

[Transferring a Properties-Only Object to the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/transferring-a-properties-only-object-to-the-device)