# IWICProgressiveLevelControl::GetCurrentLevel

## Description

Gets the decoder's current progressive level.

## Parameters

### `pnLevel` [out, retval]

Type: **UINT***

Indicates the current level specified.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The level always defaults to the highest progressive level. In order to decode a lower progressive level, [SetCurrentLevel](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicprogressivelevelcontrol-setcurrentlevel) must first be called.

## See also

[IWICProgressiveLevelControl](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicprogressivelevelcontrol)

[Progressive Decoding Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-progressive-decoding)