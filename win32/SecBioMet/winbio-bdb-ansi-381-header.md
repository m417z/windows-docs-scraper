# WINBIO\_BDB\_ANSI\_381\_HEADER structure

The **WINBIO\_BDB\_ANSI\_381\_HEADER** structure specifies information about a series of fingerprint or palm samples.

## Members

**RecordLength**

The size, in bytes, of this structure plus the size of all [**WINBIO\_BDB\_ANSI\_381\_RECORD**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bdb-ansi-381-record) structures for the fingerprint or palm samples captured from an end user. Only the low six bytes are valid.

**FormatIdentifier**

Specifies the format. Currently, this must be 0x46495200.

**VersionNumber**

Specifies the version number. Currently this must be 0x30313000 which corresponds internally to 0.1.0.0.

**ProductId**

A [**WINBIO\_REGISTERED\_FORMAT**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-registered-format) structure that contains the registered data format as an owner/type pair.

**CaptureDeviceId**

Contains the unit ID of the device used to capture the sample.

**ImageAcquisitionLevel**

Specifies the resolution level at which the sample is captured.

**HorizontalScanResolution**

Specifies the horizontal resolution of the scan.

**VerticalScanResolution**

Specifies the vertical resolution of the scan.

**HorizontalImageResolution**

Specifies the horizontal resolution of the captured fingerprint or palm image.

**VerticalImageResolution**

Specifies the vertical resolution of the captured fingerprint or palm image.

**ElementCount**

Number of finger or palm records in this structure.

**ScaleUnits**

Contains the unit of measure, 1 for inches and 2 for centimeters.

**PixelDepth**

Specifies the number of bits in a pixel. This can be 1 to 16 bits per pixel for color.

**ImageCompressionAlg**

Specifies the algorithm used to compress the finger or palm image.

**Reserved**

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

