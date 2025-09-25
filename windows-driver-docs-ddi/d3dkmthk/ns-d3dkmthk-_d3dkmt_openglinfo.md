# _D3DKMT_OPENGLINFO structure

## Description

The D3DKMT_OPENGLINFO structure describes OpenGL installable client driver (ICD) information.

## Members

### `UmdOpenGlIcdFileName` [out]

An array of wide characters that contains the file name of the OpenGL ICD.

### `Version` [out]

The version of the OpenGL ICD.

### `Flags` [in]

This member is currently unused.

## See also

[D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[D3DKMT_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)