# D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA structure

## Description

Represents key exchange output data for hardware content protection.

## Members

### `PrivateDataSize`

The size of the private data reserved for IHV usage. This size is determined from the *pPrivateOutputSize* parameter returned by the [ID3D11VideoDevice1::GetCryptoSessionPrivateDataSize](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11videodevice1-getcryptosessionprivatedatasize) function.

### `MaxHWProtectionDataSize`

The maximum size of data that the driver can return in the output buffer. The last byte that it can write to is **pbOutput**[**PrivateDataSize** + **MaxHWProtectionDataSize** – 1].

### `HWProtectionDataSize`

The size of the output data written by the driver.

### `TransportTime`

The number of 100 nanosecond units spent transporting the data.

### `ExecutionTime`

The number of 100 nanosecond units spent executing the content protection command.

### `pbOutput`

If **PrivateDataSize** is greater than 0, pbInput[0] – **pbOutput**[**PrivateDataSize** - 1] is reserved for IHV use.

**pbOutput**[**PrivateDataSize**] – **pbOutput**[**HWProtectionDataSize** + **PrivateDataSize** - 1] contains the input data for the DRM command. The format and size of the DRM command is defined by the DRM specification.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)