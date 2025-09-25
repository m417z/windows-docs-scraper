# IMSVidEncoder::get_AudioEncoderInterface

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_AudioEncoderInterface** method retrieves a pointer to the audio encoder interface.

## Parameters

### `ppEncInt` [out]

Pointer to a variable that receives an **IUnknown** interface pointer. The caller can query this interface for the [IEncoderAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi) interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the method succeeds, the caller must release the **IUnknown** interface.

## See also

[IMSVidEncoder Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidencoder)