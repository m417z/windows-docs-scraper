# PFND3D11_1DDI_GETVIDEODECODERPROFILECOUNT callback function

## Description

Queries the number of video decoder profiles that are supported by the display miniport driver.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pDecodeProfileCount* [out]

A pointer to a UINT value that specifies the maximum number of decoder profiles that are supported.