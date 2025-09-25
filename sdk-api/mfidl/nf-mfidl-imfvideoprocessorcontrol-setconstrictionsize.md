# IMFVideoProcessorControl::SetConstrictionSize

## Description

Specifies the amount of downsampling to perform on the output.

## Parameters

### `pConstrictionSize` [in]

The sampling size.

To disable constriction, set this parameter to **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFVideoProcessorControl](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideoprocessorcontrol)