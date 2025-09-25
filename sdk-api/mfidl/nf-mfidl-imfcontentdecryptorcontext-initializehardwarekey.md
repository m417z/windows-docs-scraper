# IMFContentDecryptorContext::InitializeHardwareKey

## Description

 Allows the display driver to return IHV-specific information used when initializing a new hardware key.

## Parameters

### `InputPrivateDataByteCount` [in]

The number of bytes in the buffer that *InputPrivateData* specifies.

### `InputPrivateData` [in, optional]

The contents of this parameter are defined by the implementation of
the protection system that runs in the security processor. The contents may contain data about license or stream properties.

### `OutputPrivateData` [out]

The return data is also defined by the implementation of the protection system implementation
that runs in the security processor. The contents may contain data associated with the underlying hardware key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFContentDecryptorContext](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentdecryptorcontext)