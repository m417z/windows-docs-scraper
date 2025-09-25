# XINPUT_STATE structure

## Description

Represents the state of a controller.

## Members

### `dwPacketNumber`

State packet number. The packet number indicates whether there have been any changes in the state of the controller. If the *dwPacketNumber* member is the same in sequentially returned **XINPUT_STATE** structures, the controller state has not changed.

### `Gamepad`

[XINPUT_GAMEPAD](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_gamepad) structure containing the current state of a controller.

## Remarks

The *dwPacketNumber* member is incremented only if the status of the controller has changed since the controller was last polled.

## See also

[XINPUT_GAMEPAD](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_gamepad)

[XInput Structures](https://learn.microsoft.com/windows/desktop/xinput/structures)

[XInputGetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetstate)