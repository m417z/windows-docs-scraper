# IMSVidTuner::get_Tune

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Tune** method retrieves the current tune request.

## Parameters

### `ppTR` [out]

Pointer to a variable that receives an [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The returned [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface has an outstanding reference count. The caller must release the interface.

## See also

[IMSVidTuner Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidtuner)

[IMSVidTuner::put_Tune](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidtuner-put_tune)

[The Microsoft Unified Tuning Model](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/the-microsoft-unified-tuning-model)