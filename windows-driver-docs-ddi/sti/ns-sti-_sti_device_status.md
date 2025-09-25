## Description

The **STI_DEVICE_STATUS** structure is used as a parameter to the [IStiDevice::GetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getstatus) and [IStiUSD::GetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-getstatus) methods.

## Members

### `dwSize`

Caller-supplied size, in bytes, of the STI_DEVICE_STATUS structure.

### `StatusMask`

One or more caller-supplied bit flags, indicating the type of status information being requested. The following flags are defined:

| Flag | Definition |
|---|---|
| STI_DEVSTATUS_EVENTS_STATE | The driver should fill in the **dwEventHandlingState** member. |
| STI_DEVSTATUS_ONLINE_STATE | The driver should fill in the **dwOnlineState** member. |

### `dwOnlineState`

Bit flags indicating the device's current status. The following flags are defined in *Sti.h*.

Currently use of STI_ONLINESTATE_OPERATIONAL is required, while use of all other flags is optional. (Currently, STI_ONLINESTATE_OPERATIONAL is the only flag that the still image server checks.)

#### STI_ONLINESTATE_BUSY

The device is busy.

#### STI_ONLINESTATE_ERROR

The device has reported an error.

#### STI_ONLINESTATE_INITIALIZING

The device is being initialized.

#### STI_ONLINESTATE_IO_ACTIVE

The device is active but not accepting commands.

#### STI_ONLINESTATE_OFFLINE

The device is off-line.

#### STI_ONLINESTATE_OPERATIONAL

The device is online and ready. If set, Control Panel indicates the device is ready. Otherwise, it indicates the device is off-line.

#### STI_ONLINESTATE_PAPER_JAM

The device has reported a paper jam.

#### STI_ONLINESTATE_PAPER_PROBLEM

The device has reported an unspecified paper problem.

#### STI_ONLINESTATE_PAUSED

The device is paused.

#### STI_ONLINESTATE_PENDING

I/O operations are pending.

#### STI_ONLINESTATE_POWER_SAVE

The device is in power save mode.

#### STI_ONLINESTATE_TRANSFERRING

The device is transferring data.

#### STI_ONLINESTATE_USER_INTERVENTION

The device requires user intervention.

#### STI_ONLINESTATE_WARMING_UP

The device is warming up.

### `dwHardwareStatusCode`

Optional device-specific, vendor-defined value.

### `dwEventHandlingState`

Contains bit flags indicating event status. The following flags are defined in *Sti.h*.

#### STI_EVENTHANDLING_ENABLED

*Not used*.

#### STI_EVENTHANDLING_PENDING

A device event has occurred.

#### STI_EVENTHANDLING_POLLING

*Not used*.

### `dwPollingInterval`

Time value, in milliseconds, indicating how often the device should be polled, if polling is required.