# IMFContentProtectionDevice::InvokeFunction

## Description

Calls into the implementation of the protection system in the security processor.

## Parameters

### `FunctionId` [in]

The identifier of the function that you want to run. This identifier is defined by the implementation of the protection system.

### `InputBufferByteCount` [in]

The number of bytes of in the buffer that *InputBuffer* specifies, including private data.

### `InputBuffer` [in]

A pointer to the data that you want to provide as input.

### `OutputBufferByteCount` [in, out]

Pointer to a value that specifies the length in bytes of the data that the function wrote to the buffer that *OutputBuffer* specifies, including the private data.

### `OutputBuffer` [out]

Pointer to the buffer where you want the function to write its output.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFContentProtectionDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentprotectiondevice)