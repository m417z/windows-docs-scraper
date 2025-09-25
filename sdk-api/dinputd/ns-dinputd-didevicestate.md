# DIDEVICESTATE structure

## Description

The **DIDEVICESTATE** structure returns information about the state of a force feedback device.

## Members

### `dwSize`

Specifies the size of the structure in bytes. This member must be initialized before the structure is used.

### `dwState`

Indicates various aspects of the device state. Can indicate zero, one, or more of the following:

#### DIGFFS_EMPTY

Indicates that the force feedback device is devoid of any downloaded effects.

#### DIGFFS_STOPPED

Indicates that no effects are currently playing and the device is not paused.

#### DIGFFS_PAUSED

Indicates that playback of effects has been paused by a previous DISFFC_PAUSE command.

#### DIGFFS_ACTUATORSON

Indicates that the device's force-feedback actuators are enabled.

#### DIGFFS_ACTUATORSOFF

Indicates that the device's force-feedback actuators are disabled.

#### DIGFFS_POWERON

Indicates that power to the force-feedback system is currently available. If the device cannot report the power state, then neither DIGFFS_POWERON nor DIGFFS_POWEROFF should be returned.

#### DIGFFS_POWEROFF

Indicates that power to the force-feedback system is not currently available. If the device cannot report the power state, then neither DIGFFS_POWERON nor DIGFFS_POWEROFF should be returned.

#### DIGFFS_SAFETYSWITCHON

Indicates that the safety switch (dead-man switch) is currently on, meaning that the device can operate. If the device cannot report the state of the safety switch, then neither DIGFFS_SAFETYSWITCHON nor DIGFFS_SAFETYSWITCHOFF should be returned.

#### DIGFFS_SAFETYSWITCHOFF

Indicates that the safety switch (dead-man switch) is currently off, meaning that the device cannot operate. If the device cannot report the state of the safety switch, then neither DIGFFS_SAFETYSWITCHON nor DIGFFS_SAFETYSWITCHOFF should be returned.

#### DIGFFS_USERFFSWITCHON

Indicates that the user force-feedback switch is currently on, meaning that the device can operate. If the device cannot report the state of the user force-feedback switch, then neither DIGFFS_USERFFSWITCHON nor DIGFFS_USERFFSWITCHOFF should be returned.

#### DIGFFS_USERFFSWITCHOFF

Indicates that the user force-feedback switch is currently off, meaning that the device cannot operate. If the device cannot report the state of the user force-feedback switch, then neither DIGFFS_USERFFSWITCHON nor DIGFFS_USERFFSWITCHOFF should be returned.

#### DIGFFS_DEVICELOST

Indicates that the device suffered an unexpected failure and is in an indeterminate state. It must be reset either by unacquiring and reacquiring the device, or by explicitly sending a DISFFC_RESET command. For example, the device may be lost if the user suspends the computer, causing on-board memory on the device to be lost.

### `dwLoad`

A value indicating the percentage of device memory in use. A value of zero indicates that the device memory is completely available. A value of 100 indicates that the device is full.