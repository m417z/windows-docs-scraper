# IDirectInputEffectDriver::DeviceID

## Description

The **IDirectInputEffectDriver::DeviceID**  method sends the driver the identity of the device.

## Parameters

### `unnamedParam1`

Specifies the version number of DirectInput that loaded the effect driver. For example, with DirectInput 5.0, the value of this parameter is 0x00000500.

### `unnamedParam2`

Specifies the joystick ID number. The Microsoft Windows joystick subsystem allocates external IDs.

### `unnamedParam3`

Specifies the availability of the device. This value is nonzero if access to the device is beginning, and zero if access to the device is ending.

### `unnamedParam4`

Specifies the ID of the internal joystick. The device driver manages internal IDs.

### `unnamedParam5`

Points to a [DIHIDFFINITINFO](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dihidffinitinfo) structure that contains initialization information for the force feedback driver. The driver uses this information to distinguish between multiple devices and to query DirectInput for any other device attributes.

## Return value

Returns S_OK if successful; otherwise, returns an error code.

## Remarks

As an example of the **IDirectInputEffectDriver::DeviceID**  method, if a device driver is passed *dwExternalID* = 2 and *dwInternalId* = 1, then unit 1 on the device corresponds to the joystick whose ID is 2.