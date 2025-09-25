# IBDA_DigitalDemodulator::get_SpectralInversion

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SpectralInversion** method retrieves the spectral inversion value for the signal.

## Parameters

### `pSpectralInversion` [out]

Pointer that receives a [SpectralInversion](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/spectralinversion) variable.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

For more information, see **KSPROPERTY_BDA_SPECTRAL_INVERSION** in the Windows DDK.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_DigitalDemodulator Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_digitaldemodulator)

[IBDA_DigitalDemodulator::put_SpectralInversion](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_digitaldemodulator-put_spectralinversion)