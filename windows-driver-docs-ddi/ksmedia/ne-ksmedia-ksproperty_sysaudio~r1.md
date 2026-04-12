# KSPROPERTY_SYSAUDIO enumeration

## Description

The **KSPROPERTY_SYSAUDIO** enumeration defines the properties supported by the system audio component (SysAudio) for managing virtual audio devices and filter graph construction.

## Constants

### `KSPROPERTY_SYSAUDIO_DEVICE_COUNT`

Retrieves the number of virtual audio devices managed by SysAudio.

### `KSPROPERTY_SYSAUDIO_DEVICE_FRIENDLY_NAME`

Retrieves the friendly name of a specific virtual audio device.

### `KSPROPERTY_SYSAUDIO_DEVICE_INSTANCE`

Retrieves instance information for a virtual audio device.

### `KSPROPERTY_SYSAUDIO_DEVICE_INTERFACE_NAME`

Retrieves the interface name of a virtual audio device.

### `KSPROPERTY_SYSAUDIO_SELECT_GRAPH`

Selects a specific filter graph for audio processing.

### `KSPROPERTY_SYSAUDIO_CREATE_VIRTUAL_SOURCE`

Creates a virtual audio source.

### `KSPROPERTY_SYSAUDIO_DEVICE_DEFAULT`

Specifies or retrieves the default audio device.

### `KSPROPERTY_SYSAUDIO_ALWAYS_CREATE_VIRTUAL_SOURCE`

Reserved for internal Microsoft use.

### `KSPROPERTY_SYSAUDIO_ADDREMOVE_LOCK`

Reserved for internal Microsoft use.

### `KSPROPERTY_SYSAUDIO_ADDREMOVE_UNLOCK`

Reserved for internal Microsoft use.

### `KSPROPERTY_SYSAUDIO_RENDER_PIN_INSTANCES`

Reserved for internal Microsoft use.

### `KSPROPERTY_SYSAUDIO_RENDER_CONNECTION_INDEX`

Reserved for internal Microsoft use.

### `KSPROPERTY_SYSAUDIO_CREATE_VIRTUAL_SOURCE_ONLY`

Reserved for internal Microsoft use.

### `KSPROPERTY_SYSAUDIO_INSTANCE_INFO`

Retrieves detailed instance information.

### `KSPROPERTY_SYSAUDIO_PREFERRED_DEVICE`

Reserved for internal Microsoft use.

### `KSPROPERTY_SYSAUDIO_COMPONENT_ID`

Retrieves the component identifier for a SysAudio device.

### `KSPROPERTY_SYSAUDIO_ADDREMOVE_GFX`

Reserved for internal Microsoft use.

## Remarks

The **KSPROPSETID_SysAudio** property set uses these enumeration values to identify specific properties related to system audio management. SysAudio is a Windows system component that builds and manages filter graphs for audio rendering and capture, presenting them as virtual audio devices to applications.

These properties enable applications to enumerate available audio devices, retrieve device information, select appropriate audio processing graphs, and manage virtual audio sources.

## See also

- [KSPROPERTY_SYSAUDIO_PIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_sysaudio_pin-r1)