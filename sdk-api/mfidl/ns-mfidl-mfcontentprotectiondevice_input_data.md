# MFCONTENTPROTECTIONDEVICE_INPUT_DATA structure

## Description

Contains information about the data that you want to provide as input to a protection system function.

## Members

### `HWProtectionFunctionID`

The identifier of the function that you need to run. This value is defined by the implementation of the protection system.

### `PrivateDataByteCount`

The size of the private data that the implementation of the security processor implementation reserved. You can determine this value by calling the [IMFContentProtectionDevice::GetPrivateDataByteCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectiondevice-getprivatedatabytecount) method.

### `HWProtectionDataByteCount`

The size of the data provided as input to the protection system function that you want to run.

### `Reserved`

Reserved.

### `InputData`

The data to provide as input to the protection system function.

If the value of the **PrivateDataByteCount** member is greater than 0, bytes 0 through **PrivateDataByteCount** - 1 are reserved for use by the independent hardware vendor (IHV). Bytes **PrivateDataByteCount** through **HWProtectionDataByteCount** + **PrivateDataByteCount** - 1 contain the input data for the protection system function.

The protection system specification defines the format and size of the DRM function.

## See also

[IMFContentProtectionDevice::GetPrivateDataByteCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectiondevice-getprivatedatabytecount)

[IMFContentProtectionDevice::InvokeFunction](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectiondevice-invokefunction)

[MFCONTENTPROTECTIONDEVICE_OUTPUT_DATA](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfcontentprotectiondevice_output_data)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)