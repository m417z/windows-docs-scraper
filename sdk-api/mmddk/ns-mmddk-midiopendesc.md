# MIDIOPENDESC structure

## Description

The `MIDIOPENDESC` structure is a client-filled structure that provides information about how to open a MIDI device.

## Members

### `hMidi`

Specifies the handle that the client uses to reference the device. This handle is assigned by WINMM. Use this handle when you notify the client with the [DriverCallback](https://learn.microsoft.com/previous-versions//ms708182(v=vs.85)) function.

### `dwCallback`

Specifies either the address of a callback function, a window handle, or a task handle, depending on the flags that are specified in the dwParam2 parameter of the [MODM_OPEN](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537541(v=vs.85)) message. If this field contains a handle, it is contained in the low-order word.

### `dwInstance`

Specifies a pointer to a DWORD that contains instance information for the client. This instance information is returned to the client whenever the driver notifies the client by using the **DriverCallback** function.

### `dnDevNode`

Specifies a device node for the MIDI output device, if it is a Plug and Play (PnP) MIDI device.

### `cIds`

Specifies the number of stream identifiers, if a stream is open.

### `rgIds`

Specifies an array of device identifiers. The number of identifiers is given by the **cIds** member.

## See also

[DriverCallback](https://learn.microsoft.com/previous-versions//ms708182(v=vs.85))