# MFCONTENTPROTECTIONDEVICE_OUTPUT_DATA structure

## Description

Contains information about the data you received as output from a protection system function.

## Members

### `PrivateDataByteCount`

The size of the private data that the implementation of the security processor reserves, in bytes. You can determine this value by calling the [IMFContentProtectionDevice::GetPrivateDataByteCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectiondevice-getprivatedatabytecount) method.

### `MaxHWProtectionDataByteCount`

The maximum size of data that the independent hardware vendor (IHV) can return in the output buffer, in bytes.

### `HWProtectionDataByteCount`

The size of the data that the IHV wrote to the output buffer, in bytes.

### `Status`

The result of the protection system function.

### `TransportTimeInHundredsOfNanoseconds`

The number of 100 nanosecond units spent transporting the data.

### `ExecutionTimeInHundredsOfNanoseconds`

The number of 100 nanosecond units spent running the protection system function.

### `OutputData`

The output of the protection system function.

If the value of the **PrivateDataByteCount** member is greater than 0, bytes 0 through **PrivateDataByteCount** - 1 are reserved for IHV use.
Bytes **PrivateDataByteCount** through **MaxHWProtectionDataByteCount** + **PrivateDataByteCount** - 1 contain the region
of the array into which the driver should return the output data from the protection system function.

The protection system specification defines the format and size of the
function.

## See also

[IMFContentProtectionDevice::GetPrivateDataByteCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectiondevice-getprivatedatabytecount)

[IMFContentProtectionDevice::InvokeFunction](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectiondevice-invokefunction)

[MFCONTENTPROTECTIONDEVICE_INPUT_DATA](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfcontentprotectiondevice_input_data)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)