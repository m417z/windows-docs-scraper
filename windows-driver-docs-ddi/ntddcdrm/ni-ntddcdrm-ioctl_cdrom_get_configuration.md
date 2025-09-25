# IOCTL_CDROM_GET_CONFIGURATION IOCTL

## Description

Requests feature and profile information from a CD-ROM device.

Multimedia devices have different characteristics depending on the type of media that is in the device. To provide drivers with a means of querying multimedia devices about these varying characteristics, the *SCSI Multimedia - 3* (*MMC-3*) specification defines a command called "GET CONFIGURATION." This command permits drivers to query a device for both permanent information about the device and information that varies whenever the media changes. In Microsoft Windows 2000 and later operating systems, drivers can send this query to a device using the IOCTL_CDROM_GET_CONFIGURATION request.

The IOCTL_CDROM_GET_CONFIGURATION request returns a list of descriptors that describe the capabilities of the device for the current medium. These descriptors are divided into two groups called "feature descriptors" and "profile list descriptors." A feature specifies the capabilities of a device and its associated medium. A profile is a collection of features. If the device supports a profile, it supports all the features in the profile.

See the *MMC-3* specification for further discussion concerning features and profiles.

## Parameters

### Major code

### Input buffer

Input buffer.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the IO_STACK_LOCATION structure indicates the size, in bytes, of the input buffer, which must be = **sizeof**(GET_CONFIGURATION_IOCTL_INPUT).

### Output buffer

The driver returns the feature and profile data in the buffer at **Irp->AssociatedIrp.SystemBuffer**. The data begins with a header of type [GET_CONFIGURATION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_get_configuration_header). Feature data is reported in the space immediately following this header. Its size and formatting depend on which features are reported.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**(GET_CONFIGURATION_HEADER).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes that are returned. The **Status** field is set to STATUS_SUCCESS if the request succeeds. If the **Parameters.DeviceIoControl.InputBufferLength** does not have the correct value, the request fails with a STATUS_INFO_LENGTH_MISMATCH error. If **Parameters.DeviceIoControl.OutputBufferLength** is not large enough, the request fails with a STATUS_BUFFER_TOO_SMALL error. If the value for the output buffer is too large, the request fails a STATUS_INVALID_BUFFER_SIZE message.

## See also

[GET_CONFIGURATION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_get_configuration_header)

[GET_CONFIGURATION_IOCTL_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_get_configuration_ioctl_input)