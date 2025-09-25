# PFND3D11_1DDI_CHECKVIDEODECODERFORMAT callback function

## Description

Determines whether a specified format can be used as a video decoder output format for a specified DirectX Video Acceleration (DXVA) profile.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDecoderProfile* [in]

A pointer to a GUID that identifies the DXVA profile.

### `unnamedParam3`

*Format* [in]

A DXGI_FORMAT value that specifies the output format. Typical values include DXGI_FORMAT_NV12 and DXGI_FORMAT_420_OPAQUE.

### `unnamedParam4`

*pBool* [out]

A BOOL value that, if TRUE, specifies that the specified format can be used for the specified DXVA profile.

## Remarks

This function is not expected to fail.