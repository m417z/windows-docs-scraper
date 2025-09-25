# IPart::GetLocalId

## Description

The **GetLocalId** method gets the local ID of this part.

## Parameters

### `pnId` [out]

Pointer to a **UINT** variable into which the method writes the local ID of this part.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pnId* is **NULL**. |

## Remarks

When you have a pointer to a part object, you can call this method to get the local ID of the part. A local ID is a number that uniquely identifies a part among all parts in a device topology.

The [IAudioInputSelector::GetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudioinputselector-getselection) and [IAudioOutputSelector::GetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiooutputselector-getselection) methods retrieve the local ID of a connected part. The [IAudioInputSelector::SetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudioinputselector-setselection) and [IAudioOutputSelector::SetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiooutputselector-setselection) methods select the input or output that is connected to a part that is identified by its local ID. The [IDeviceTopology::GetPartById](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getpartbyid) method gets a part that is identified by its local ID.

For code examples that use the **GetLocalId** method, see the following topics:

* [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies)
* [Using the IKsControl Interface to Access Audio Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-ikscontrol-interface-to-access-audio-properties)

## See also

[IAudioInputSelector::GetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudioinputselector-getselection)

[IAudioInputSelector::SetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudioinputselector-setselection)

[IAudioOutputSelector::GetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiooutputselector-getselection)

[IAudioOutputSelector::SetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiooutputselector-setselection)

[IDeviceTopology::GetPartById](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getpartbyid)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)