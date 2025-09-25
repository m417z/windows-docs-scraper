# ITunerCap::get_AuxInputCount

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **get_AuxInputCount** method retrieves a count of the number of auxiliary inputs on the TV tuner.

## Parameters

### `pulCompositeCount` [in, out]

Receives a count of the number of composite-video input connectors on the device.

### `pulSvideoCount` [in, out]

Receives a count of the number of S-video input connectors on the device.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

**Note**The *pulCompositeCount* and *pulSvideoCount* parameters are marked in the IDL file as [in, out] but are used as [out] parameters. To preserve binary compatibility with previous versions, they have not been changed.

## See also

[ITunerCap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunercap)