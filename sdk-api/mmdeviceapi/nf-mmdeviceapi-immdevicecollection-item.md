# IMMDeviceCollection::Item

## Description

The **Item** method retrieves a pointer to the specified item in the device collection.

## Parameters

### `nDevice` [in]

The device number. If the collection contains *n* devices, the devices are numbered 0 to *n*– 1.

### `ppDevice` [out]

Pointer to a pointer variable into which the method writes the address of the [IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice) interface of the specified item in the device collection. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **Item** call fails, **ppDevice* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *ppDevice* is **NULL**. |
| **E_INVALIDARG** | Parameter *nDevice* is not a valid device number. |

## Remarks

This method retrieves a pointer to the **IMMDevice** interface of the specified item in the device collection. Each item in the collection is an endpoint object that represents an audio endpoint device. The caller selects a device from the device collection by specifying the device number. For a collection of *n* devices, valid device numbers range from 0 to *n*– 1. To obtain a count of the devices in a collection, call the [IMMDeviceCollection::GetCount](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevicecollection-getcount) method.

For a code example that calls the **Item** method, see [Device Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/device-properties).

## See also

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)

[IMMDeviceCollection Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevicecollection)

[IMMDeviceCollection::GetCount](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevicecollection-getcount)