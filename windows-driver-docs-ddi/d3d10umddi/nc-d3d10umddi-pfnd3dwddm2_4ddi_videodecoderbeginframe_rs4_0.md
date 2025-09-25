# PFND3DWDDM2_4DDI_VIDEODECODERBEGINFRAME_RS4_0 callback function

## Description

Starts a DirectX Video Acceleration (DXVA) decoding operation to decode a video frame.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hDecode`

A handle to the video decoder object that was created through a call to the CreateVideoDecoder function.

### `pBeginFrame`

A pointer to a D3DWDDM2_4DDIARG_VIDEODECODERBEGINFRAME_RS4_0 structure. For more information, see the Remarks section.

## Return value

Returns one of the following HRESULT values:

| Return code | Description |
|---|---|
|S_OK|The session key for the cryptographic session was negotiated successfully.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Prototype

```cpp
//Declaration

PFND3DWDDM2_4DDI_VIDEODECODERBEGINFRAME_RS4_0 Pfnd3dwddm24DdiVideodecoderbeginframeRs40;

// Definition

HRESULT Pfnd3dwddm24DdiVideodecoderbeginframeRs40
(
	D3D10DDI_HDEVICE hDevice
	D3D11_1DDI_HDECODE hDecode
	CONST D3DWDDM2_4DDIARG_VIDEODECODERBEGINFRAME_RS4_0 *pBeginFrame
)
{...}

PFND3DWDDM2_4DDI_VIDEODECODERBEGINFRAME_RS4_0

```

## Remarks

If this function returns S_OK, the Microsoft Direct3D runtime calls the VideoDecoderSubmitBuffers function to perform the decoding operations. When all decoding operations have been executed, the runtime calls the VideoDecoderEndFrame function to stop the decoding operation on a video frame.

> [!NOTE]
> Each call to VideoDecoderBeginFrame must have a matching call to VideoDecoderEndFrame, and VideoDecoderBeginFrame calls cannot be nested.

The [D3DWDDM2_4DDIARG_VIDEODECODERBEGINFRAME_RS4_0](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_4ddiarg_videodecoderbeginframe_rs4_0) structure contains the following data:

* The resource that will receive the decrypted and decoded data.
* A content key that was used to encrypt the video frame data.

If the *pContentKey* member of this structure is not set to NULL, the buffer that is referenced by this member contains a per-frame content key. This key must be used to decrypt the data instead of using the session key.

> [!NOTE]
> If the *pContentKey* member is not set to NULL, the buffer that is referenced by this member is encrypted by using the session key with the AES-ECB algorithm.

If the pContentKey member is set to NULL, the video frame data should be decrypted by using the session key.

## See also

[CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)
[NegotiateCryptoSessionKeyeExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_4ddi_negotiatecryptosessionkeyexchange)