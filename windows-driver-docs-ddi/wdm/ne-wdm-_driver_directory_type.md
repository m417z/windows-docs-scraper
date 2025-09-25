# _DRIVER_DIRECTORY_TYPE enumeration

## Description

Defines values for the type of directory used by the driver to load and store files. This enumeration is used by the [**IoGetDriverDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverdirectory) function. The files in that directory apply to a specific driver object.

## Constants

### `DriverDirectoryImage`

The directory from which the driver was loaded.

### `DriverDirectoryData`
The requested directory is a general-purpose directory in which the driver stores files that contain state information specific to the internals of the driver and only used by the driver itself.

### `DriverDirectorySharedData`
The requested directory is a general-purpose directory in which the driver stores or reads files that contain state information that is meant to be shared between the driver and other components. Other components can access this directory using GetSharedServiceDirectory. This value is available on Windows Server 2022 and later versions of Windows.

## Remarks

## See also

[**IoGetDriverDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverdirectory)