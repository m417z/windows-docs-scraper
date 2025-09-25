# _D3DDDIARG_SETSTREAMSOURCEFREQ structure

## Description

The D3DDDIARG_SETSTREAMSOURCEFREQ structure describes how the frequency divisor for a portion of the vertex stream source is set.

## Members

### `Stream` [in]

The stream source to divide, which is a value between zero and the maximum number of streams that are specified by the driver.

### `Divider` [in]

The frequency divisor of the portion of the vertex stream.

## See also

[SetStreamSourceFreq](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsourcefreq)