# IMFContentProtectionDevice::GetPrivateDataByteCount

## Description

 Gets the required number of bytes that need to be prepended to
the input and output buffers when you call the security processor through the [InvokeFunction](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectiondevice-invokefunction) method.
When you specify this number of bytes, the Media Foundation transform (MFT) decryptor can allocate the total amount of bytes and can avoid making copies of the data when the decryptor moves the data to the security processor.

## Parameters

### `PrivateInputByteCount` [out]

The required number of bytes that need to be prepended to
the input buffer that you supply to content protection system.

### `PrivateOutputByteCount` [out]

The required number of bytes that need to be prepended to
the output buffer that you supply to content protection system.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFContentProtectionDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentprotectiondevice)

[InvokeFunction](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectiondevice-invokefunction)