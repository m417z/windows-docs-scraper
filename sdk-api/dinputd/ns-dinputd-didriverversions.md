# DIDRIVERVERSIONS structure

## Description

The **DIDRIVERVERSIONS** structure is used by the DirectInput effect driver to report version information back to DirectInput. The semantics of the version numbers are left to the discretion of the device driver. The only requirement is that later versions have higher version numbers than earlier versions.

## Members

### `dwSize`

Specifies the size of the structure in bytes. This member must be initialized before the structure is used.

### `dwFirmwareRevision`

Specifies the firmware revision of the device.

### `dwHardwareRevision`

Specifies the hardware revision of the device.

### `dwFFDriverVersion`

Specifies the version number of the force-feedback device driver.