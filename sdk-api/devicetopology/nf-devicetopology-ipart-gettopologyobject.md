# IPart::GetTopologyObject

## Description

The **GetTopologyObject** method gets a reference to the [IDeviceTopology](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology) interface of the device-topology object that contains this part.

## Parameters

### `ppTopology` [out]

Pointer to a pointer variable into which the method writes the address of the **IDeviceTopology** interface of the device-topology object. The caller obtains a counted reference to the interface from this method. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetTopologyObject** call fails, **ppTopology* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *ppTopology* is **NULL**. |

## Remarks

For code examples that use this method, see the following topics:

* [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies)
* [Using the IKsControl Interface to Access Audio Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-ikscontrol-interface-to-access-audio-properties)

## See also

[IDeviceTopology Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)