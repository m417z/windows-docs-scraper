# IConnector::GetDeviceIdConnectedTo

## Description

The **GetDeviceIdConnectedTo** method gets the device identifier of the audio device, if any, that this connector is connected to.

## Parameters

### `ppwstrDeviceId` [out]

Pointer to a string pointer into which the method writes the address of a null-terminated, wide-character string that contains the device identifier of the connected device. The method allocates the storage for the string. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the **GetDeviceIdConnectedTo** call fails, **ppwstrDeviceId* is **NULL**. For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *ppwstrDeviceId* is **NULL**. |
| **E_NOTFOUND** | This connector is not connected, or the other side of the connection is not another device topology (for example, a Software_IO connection). |
| **E_MEMORY** | Out of memory. |

## Remarks

The device identifier obtained from this method can be used as an input parameter to the [IMMDeviceEnumerator::GetDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdevice) method.

This method is functionally equivalent to, but more efficient than, the following series of method calls:

* Call the [IConnector::GetConnectedTo](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iconnector-getconnectedto) method to obtain the [IConnector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector) interface of the "to" connector.
* Call the **IConnector::QueryInterface** method (with parameter *iid* set to **REFIID** IID_IPart) to obtain the [IPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart) interface of the "to" connector.
* Call the [IPart::GetTopologyObject](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-gettopologyobject) method to obtain the [IDeviceTopology](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology) interface of the "to" device (the device that contains the "to" connector).
* Call the [IDeviceTopology::GetDeviceId](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getdeviceid) method to obtain the device ID of the "to" device.

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)

[IMMDeviceEnumerator::GetDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdevice)