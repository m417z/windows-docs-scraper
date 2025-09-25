# ITAutomatedPhoneControl::StartRinger

## Description

The
**StartRinger** method starts the phone's ringer, specifying the ring mode and the duration of the ring.

## Parameters

### `lRingMode` [in]

Ring mode. The exact meaning of this value is device-dependent. For more information, see the following Remarks section.

### `lDuration` [in]

Length of ring.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

If you specify the value zero in the *lRingMode* parameter, and the phone doesn't have a ringer device, the
**StartRinger** method attempts to play the ringing sound on the system's default audio render device. Examples of default devices include sound card speakers and a USB phone's audio render device. For more information, see
[PHONECAPS_LONG](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_long).

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)