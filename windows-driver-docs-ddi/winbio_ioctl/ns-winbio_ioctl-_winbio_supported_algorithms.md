# _WINBIO_SUPPORTED_ALGORITHMS structure

## Description

The WINBIO_SUPPORTED_ALGORITHMS structure is the OUT payload for [IOCTL_BIOMETRIC_GET_SUPPORTED_ALGORITHMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_get_supported_algorithms).

## Members

### `PayloadSize`

Specifies the total size of the payload, which includes the fixed length structure and any variable data at the end.

### `WinBioHresult`

Specifies the HRESULT status of the I/O operation.

### `NumberOfAlgorithms`

Specifies the number of algorithms in the data block.

### `AlgorithmData`

Specifies a structure of type [WINBIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_data) that contains NULL-terminated UTF-8 OID strings that represent the algorithms supported by the device.

## See also

[IOCTL_BIOMETRIC_GET_SUPPORTED_ALGORITHMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_get_supported_algorithms)