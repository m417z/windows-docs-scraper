# IAudioOutputSelector::SetSelection

## Description

The **SetSelection** method selects one of the outputs of the output selector.

## Parameters

### `nIdSelect` [in]

The new selector output. The caller should set this parameter to the local ID of a part that has a direct link to one of the selector outputs.

### `pguidEventContext` [in]

Context value for the [IControlChangeNotify::OnNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolchangenotify-onnotify) method. This parameter points to an event-context GUID. If the **SetSelection** call changes the state of the output-selector control, all clients that have registered [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interfaces with that control receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the control-change event. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nIdSelect* is not the local ID of a part at a selector output. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

A local ID is a number that uniquely identifies a part among all parts in a device topology. To obtain the local ID of a part, call the [IPart::GetLocalId](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-getlocalid) method on the part object.

## See also

[IAudioOutputSelector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiooutputselector)

[IPart::GetLocalId](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-getlocalid)