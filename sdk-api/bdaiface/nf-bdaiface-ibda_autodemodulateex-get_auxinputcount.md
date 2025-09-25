# IBDA_AutoDemodulateEx::get_AuxInputCount

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_AuxInputCount** method retrieves a count of the number of auxiliary inputs on the demodulator.

## Parameters

### `pulCompositeCount` [in, out]

Pointer to a variable that receives a count of the number of composite-video input connectors on the device.

### `pulSvideoCount` [in, out]

Pointer to a variable that receives a count of the number of S-Video input connectors on the device.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

**Note**The *pulCompositeCount* and *pulSvideoCount* parameters are marked in the IDL file as [in, out] but are used as [out] parameters. To preserve binary compatibility with previous versions, they have not been changed.

## See also

[IBDA_AutoDemodulateEx Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_autodemodulateex)