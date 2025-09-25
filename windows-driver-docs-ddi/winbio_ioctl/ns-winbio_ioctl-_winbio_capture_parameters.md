# _WINBIO_CAPTURE_PARAMETERS structure

## Description

The [IOCTL_BIOMETRIC_CAPTURE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_capture_data) IOCTL uses the WINBIO_CAPTURE_PARAMETERS structure as input.

## Members

### `PayloadSize`

The total size of the payload.

### `Purpose`

A WINBIO_BIR_PURPOSE purpose, that specifies how captured data is to be used, and as a result, how it should be optimized. Some sensors will go into a different mode depending on the reason for the data capture.

The following code example shows the possible bitmask values for WINBIO_BIR_PURPOSE:

```cpp
#define WINBIO_NO_PURPOSE_AVAILABLE                     ((WINBIO_BIR_PURPOSE)0x00)
#define WINBIO_PURPOSE_VERIFY                           ((WINBIO_BIR_PURPOSE)0x01)
#define WINBIO_PURPOSE_IDENTIFY                         ((WINBIO_BIR_PURPOSE)0x02)
#define WINBIO_PURPOSE_ENROLL                           ((WINBIO_BIR_PURPOSE)0x04)
#define WINBIO_PURPOSE_ENROLL_FOR_VERIFICATION          ((WINBIO_BIR_PURPOSE)0x08)
#define WINBIO_PURPOSE_ENROLL_FOR_IDENTIFICATION        ((WINBIO_BIR_PURPOSE)0x10)
#define WINBIO_PURPOSE_AUDIT                            ((WINBIO_BIR_PURPOSE)0x80)
```

### `Format`

Specifies the [WINBIO_REGISTERED_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_registered_format) format of the data to be returned.

### `VendorFormat`

An optional WINBIO_UUID vendor GUID. This indicates the preferred format of the vendor-specific data in the BIR.

### `Flags`

Specifies the WINBIO_BIR_DATA_FLAGS level of processing and other attributes for the data to be returned. If format owner and type are the Windows standard, this must be WINBIO_DATA_FLAG_RAW.

The following code example shows the possible bitmask values for WINBIO_BIR_DATA_FLAGS:

```cpp
#define WINBIO_DATA_FLAG_PRIVACY                ((UCHAR)0x02)
#define WINBIO_DATA_FLAG_INTEGRITY              ((UCHAR)0x01)
#define WINBIO_DATA_FLAG_SIGNED                 ((UCHAR)0x04)

#define WINBIO_DATA_FLAG_RAW                    ((UCHAR)0x20)
#define WINBIO_DATA_FLAG_INTERMEDIATE           ((UCHAR)0x40)
#define WINBIO_DATA_FLAG_PROCESSED              ((UCHAR)0x80)

#define WINBIO_DATA_FLAG_OPTION_MASK_PRESENT    ((UCHAR)0x08)   // Always '1'.
```

## See also

[IOCTL_BIOMETRIC_CAPTURE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_capture_data)