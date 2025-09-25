# IMSVidDeviceEvent::StateChange

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP or later.

The **StateChange** method signals that the state of the device has changed.

## Parameters

### `lpd` [in]

Pointer to the device object that signaled the change.

### `oldState` [in]

Specifies the old state as an [MSVidCtlStateList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/ne-msvidctl-msvidctlstatelist) value.

### `newState` [in]

Specifies the new state as an [MSVidCtlStateList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/ne-msvidctl-msvidctlstatelist) value.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The dispatch identifier (dispid) of this method is **eventidStateChange**.

## See also

[IMSVidDeviceEvent](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddeviceevent)