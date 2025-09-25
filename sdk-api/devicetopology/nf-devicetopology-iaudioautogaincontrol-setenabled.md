# IAudioAutoGainControl::SetEnabled

## Description

The **SetEnabled** method enables or disables the AGC.

## Parameters

### `bEnable` [in]

The new AGC state. If this parameter is **TRUE** (nonzero), the method enables AGC. If **FALSE**, it disables AGC.

### `pguidEventContext` [in]

Context value for the [IControlChangeNotify::OnNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolchangenotify-onnotify) method. This parameter points to an event-context GUID. If the **SetEnabled** call changes the state of the AGC control, all clients that have registered [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interfaces with that control receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the control-change event. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

A disabled AGC control operates in pass-through mode. In this mode, the audio stream passes through the control without modification.

## See also

[IAudioAutoGainControl Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioautogaincontrol)