# IDeviceTopology::GetPartById

## Description

The **GetPartById** method gets a part that is identified by its local ID.

## Parameters

### `nId` [in]

The part to get. This parameter is the local ID of the part. For more information, see Remarks.

### `ppPart` [out]

Pointer to a pointer variable into which the method writes the address of the [IPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart) interface of the part object that is identified by *nId*. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetPartById** call fails, **ppPart* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nId* is not a valid local ID. |
| **E_POINTER** | Pointer *ppPart* is **NULL**. |

## Remarks

A local ID is a number that uniquely identifies a part among all the parts in a device topology. The [IAudioInputSelector::GetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudioinputselector-getselection) and [IAudioOutputSelector::GetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiooutputselector-getselection) methods retrieve the local ID of a connected part. The [IAudioInputSelector::SetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudioinputselector-setselection) and [IAudioOutputSelector::SetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiooutputselector-setselection) methods select the input or output that is connected to a part that is identified by its local ID. When you have a pointer to a part object, you can call the [IPart::GetLocalId](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-getlocalid) method to get the local ID of the part.

## See also

[IAudioInputSelector::GetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudioinputselector-getselection)

[IAudioInputSelector::SetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudioinputselector-setselection)

[IAudioOutputSelector::GetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiooutputselector-getselection)

[IAudioOutputSelector::SetSelection](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiooutputselector-setselection)

[IDeviceTopology Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)

[IPart::GetLocalId](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-getlocalid)