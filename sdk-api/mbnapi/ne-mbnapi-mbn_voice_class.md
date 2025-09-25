# MBN_VOICE_CLASS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

 The **MBN_VOICE_CLASS** enumerated type specifies a device's voice capabilities and how they interact with the data service.

## Constants

### `MBN_VOICE_CLASS_NONE:0`

The device voice class is unknown.

### `MBN_VOICE_CLASS_NO_VOICE:0x1`

The device does not support voice calls.

### `MBN_VOICE_CLASS_SEPARATE_VOICE_DATA:0x2`

The device supports voice calls, but does not support simultaneous voice and data.

### `MBN_VOICE_CLASS_SIMULTANEOUS_VOICE_DATA:0x3`

The device supports simultaneous voice and data.