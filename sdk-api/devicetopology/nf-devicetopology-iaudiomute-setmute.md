# IAudioMute::SetMute

## Description

The **SetMute** method enables or disables the mute control.

## Parameters

### `bMuted` [in]

The new muting state. If *bMuted* is **TRUE** (nonzero), the method enables muting. If **FALSE**, the method disables muting.

### `pguidEventContext` [in]

Context value for the [IControlChangeNotify::OnNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolchangenotify-onnotify) method. This parameter points to an event-context GUID. If the **SetMute** call changes the state of the mute control, all clients that have registered [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interfaces with that control receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the control-change event. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Out of memory. |

## See also

[IAudioMute Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiomute)