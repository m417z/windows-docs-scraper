# GETVERSIONINPARAMS structure

## Description

The GETVERSIONINPARAMS structure is used in conjunction with the **SMART_GET_VERSION** request to retrieve version information, a capabilities mask, and a bitmask for the indicated device.

## Members

### `bVersion`

Contains an integer that indicates the version number of the binary driver.

### `bRevision`

Contains an integer that indicates the revision number of the binary driver.

### `bReserved`

Reserved.

### `bIDEDeviceMap`

Contains the bitmap. The following table explains the meaning of the bitmap:

| Bitmap Flags | Meaning |
| ------------ | ------- |
| Bit 0 is set to 1. | The device is either a SATA drive or an IDE drive. If it is an IDE drive, it is the master device on the primary channel. |
| Bit 1 is set to 1. | The device is an IDE drive, and it is the subordinate device on the primary channel. |
| Bit 2 is set to 1. | The device is an IDE drive, and it is the master device on the secondary channel. |
| Bit 3 is set to 1. | The device is an IDE drive, and it is the subordinate device on the secondary channel. |
| Bit 4 is set to 1. | The device is an ATAPI drive, and it is the master device on the primary channel. |
| Bit 5 is set to 1. | The device is an ATAPI drive, and it is the subordinate device on the primary channel. |
| Bit 6 is set to 1. | The device is an ATAPI drive, and it is the master device on the secondary channel. |
| Bit 7 is set to 1. | The device is an ATAPI drive, and it is the subordinate device on the secondary channel. |

### `fCapabilities`

Contains the bitmask of driver capabilities.

| Bitmap Flags | Meaning |
| ------------ | ------- |
| CAP_ATA_ID_CMD | The device supports the ATA ID command. |
| CAP_ATAPI_ID_CMD | The device supports the ATAPI ID command. |
| CAP_SMART_CMD | The device supports SMART commands. |

### `dwReserved`

Reserved.

## Remarks

The **SMART_GET_VERSION** control code returns version information, a capabilities mask, and a bitmask for the device. This IOCTL must be handled by drivers that support Self-Monitoring Analysis and Reporting Technology (SMART).

* Input Parameters

  **Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the buffer, which must be >= sizeof(GETVERSIONINPARAMS).

* Output Parameters

 The driver returns the information to the buffer at Irp->AssociatedIrp.SystemBuffer.

* I/O Status Block

 The driver sets the Information field to sizeof(GETVERSIONINPARAMS) when it sets the Status field to STATUS_SUCCESS. Otherwise, the driver sets the Information field to zero and sets the Status field to possibly STATUS_INVALID_PARAMETER.