# IWMResamplerProps::SetUserChannelMtx

## Description

Specifies the channel matrix.

## Parameters

### `userChannelMtx` [in]

Pointer to an array of floating-point values that represents a channel conversion matrix.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is equivalent to setting the [MFPKEY_WMRESAMP_CHANNELMTX](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmresamp-channelmtx) property, except that the matrix is represented differently:

* Values are floating point.
* The matrix is transposed.

To convert from the integer values given in the MFPKEY_WMRESAMP_CHANNELMTX property to floating-point values, use the following formula:

`(float)pow(10.0,((double)Coeff)/(65536.0*20.0))`

where *Coeff* is an integer coefficient.

## See also

[IWMResamplerProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmresamplerprops)