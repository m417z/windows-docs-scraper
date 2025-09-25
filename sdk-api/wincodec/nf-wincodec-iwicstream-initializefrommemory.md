# IWICStream::InitializeFromMemory

## Description

Initializes a stream to treat a block of memory as a stream. The stream cannot grow beyond the buffer size.

## Parameters

### `pbBuffer` [in]

Type: **BYTE***

Pointer to the buffer used to initialize the stream.

### `cbBufferSize` [in]

Type: **DWORD**

The size of buffer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should be avoided whenever possible. The caller is responsible for ensuring the memory block is valid for the lifetime of the stream when using **InitializeFromMemory**. A workaround for this behavior is to create an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) and use [InitializeFromIStream](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicstream-initializefromistream) to create the [IWICStream](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicstream).

If you require a growable memory stream, use [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal).