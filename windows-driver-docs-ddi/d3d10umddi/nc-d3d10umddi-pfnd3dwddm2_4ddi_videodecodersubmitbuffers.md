# PFND3DWDDM2_4DDI_VIDEODECODERSUBMITBUFFERS callback function

## Description

Submits one or more video frame buffers for DirectX Video Acceleration (DXVA) decoding.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `hDecode` [in]

A handle to the video decoder object that was created through a call to the CreateVideoDecoder function.

### `BufferCount` [in]

The number of buffers in the array that is referenced by the pBufferDesc parameter.

### `pBufferDesc` [in]

A pointer to an array of one or more D3DWDDM2_4DDI_VIDEO_DECODER_BUFFER_DESC structures. For more information, see the Remarks section.

## Return value

Returns one of the following HRESULT values:

| Return code | Description |
|---|---|
|S_OK|The session key for the cryptographic session was negotiated successfully.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Prototype

```cpp
//Declaration

PFND3DWDDM2_4DDI_VIDEODECODERSUBMITBUFFERS Pfnd3dwddm24DdiVideodecodersubmitbuffers;

// Definition

HRESULT Pfnd3dwddm24DdiVideodecodersubmitbuffers
(
	D3D10DDI_HDEVICE hDevice
	D3D11_1DDI_HDECODE hDecode
	UINT BufferCount
	CONST D3DWDDM2_4DDI_VIDEO_DECODER_BUFFER_DESC *pBufferDesc
)
{...}

PFND3DWDDM2_4DDI_VIDEODECODERSUBMITBUFFERS

```

## Remarks

The *pBufferDesc* parameter points to an array of one or more D3DWDDM2_4DDI_VIDEO_DECODER_BUFFER_DESC structures. Each element in the array describes a compressed video frame buffer that is submitted for decoding.

Each D3DWDDM2_4DDI_VIDEO_DECODER_BUFFER_DESC structure includes the following data:

* The resource that will receive the decrypted and decode frame buffers.
* A D3D11_1DDI_ENCRYPTED_BLOCK_INFO structure that specifies which bytes of the frame buffer are encrypted.
* A pointer to a D3D11_1DDI_AES_CTR_IV structure that contains an initialization vector (IV) for the frame buffer data that was encrypted by using the 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher encryption algorithm.

> [!NOTE]
> If the decode buffer does not contain any encrypted data, this pointer is set to NULL. This function does not honor a Microsoft Direct3D 11 predicate that may have been set.

## See also