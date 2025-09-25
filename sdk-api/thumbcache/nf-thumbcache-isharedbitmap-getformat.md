# ISharedBitmap::GetFormat

## Description

Retrieves the alpha type of the bitmap image.

## Parameters

### `pat` [out]

Type: **WTS_ALPHATYPE***

When this method returns, contains a pointer to the alpha type of the bitmap image. One of the following values.

#### WTSAT_RGB

The bitmap does not contain an alpha channel for transparency.

#### WTSAT_ARGB

The bitmap contains an alpha channel for transparency.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.