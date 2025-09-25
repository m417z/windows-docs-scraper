# STORAGE_DEVICE_NUMBER structure

## Description

Contains information about a device. This structure is used by the [IOCTL_STORAGE_GET_DEVICE_NUMBER](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_get_device_number) control code.

## Members

### `DeviceType`

The type of device. Values from 0 through 32,767 are reserved for use by Microsoft. Values from 32,768 through 65,535 are reserved for use by other vendors. The following values are defined by Microsoft:

#### FILE_DEVICE_8042_PORT

#### FILE_DEVICE_ACPI

#### FILE_DEVICE_BATTERY

#### FILE_DEVICE_BEEP

#### FILE_DEVICE_BLUETOOTH

#### FILE_DEVICE_BUS_EXTENDER

#### FILE_DEVICE_CD_ROM

#### FILE_DEVICE_CD_ROM_FILE_SYSTEM

#### FILE_DEVICE_CHANGER

#### FILE_DEVICE_CONTROLLER

#### FILE_DEVICE_CRYPT_PROVIDER

#### FILE_DEVICE_DATALINK

#### FILE_DEVICE_DFS

#### FILE_DEVICE_DFS_FILE_SYSTEM

#### FILE_DEVICE_DFS_VOLUME

#### FILE_DEVICE_DISK

#### FILE_DEVICE_DISK_FILE_SYSTEM

#### FILE_DEVICE_DVD

#### FILE_DEVICE_FILE_SYSTEM

#### FILE_DEVICE_FIPS

#### FILE_DEVICE_FULLSCREEN_VIDEO

#### FILE_DEVICE_INFINIBAND

#### FILE_DEVICE_INPORT_PORT

#### FILE_DEVICE_KEYBOARD

#### FILE_DEVICE_KS

#### FILE_DEVICE_KSEC

#### FILE_DEVICE_MAILSLOT

#### FILE_DEVICE_MASS_STORAGE

#### FILE_DEVICE_MIDI_IN

#### FILE_DEVICE_MIDI_OUT

#### FILE_DEVICE_MODEM

#### FILE_DEVICE_MOUSE

#### FILE_DEVICE_MULTI_UNC_PROVIDER

#### FILE_DEVICE_NAMED_PIPE

#### FILE_DEVICE_NETWORK

#### FILE_DEVICE_NETWORK_BROWSER

#### FILE_DEVICE_NETWORK_FILE_SYSTEM

#### FILE_DEVICE_NETWORK_REDIRECTOR

#### FILE_DEVICE_NULL

#### FILE_DEVICE_PARALLEL_PORT

#### FILE_DEVICE_PHYSICAL_NETCARD

#### FILE_DEVICE_PRINTER

#### FILE_DEVICE_SCANNER

#### FILE_DEVICE_SCREEN

#### FILE_DEVICE_SERENUM

#### FILE_DEVICE_SERIAL_MOUSE_PORT

#### FILE_DEVICE_SERIAL_PORT

#### FILE_DEVICE_SMARTCARD

#### FILE_DEVICE_SMB

#### FILE_DEVICE_SOUND

#### FILE_DEVICE_STREAMS

#### FILE_DEVICE_TAPE

#### FILE_DEVICE_TAPE_FILE_SYSTEM

#### FILE_DEVICE_TERMSRV

#### FILE_DEVICE_TRANSPORT

#### FILE_DEVICE_UNKNOWN

#### FILE_DEVICE_VDM

#### FILE_DEVICE_VIDEO

#### FILE_DEVICE_VIRTUAL_DISK

#### FILE_DEVICE_VMBUS

#### FILE_DEVICE_WAVE_IN

#### FILE_DEVICE_WAVE_OUT

#### FILE_DEVICE_WPD

### `DeviceNumber`

The number of this device.

### `PartitionNumber`

The partition number of the device, if the device can be partitioned. Otherwise, this member is –1.

## Remarks

The values in the **STORAGE_DEVICE_NUMBER** structure are guaranteed to remain unchanged until the device is removed or the system is restarted. They are not guaranteed to be persistent across device or system restarts.

## See also

[IOCTL_STORAGE_GET_DEVICE_NUMBER](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_get_device_number)