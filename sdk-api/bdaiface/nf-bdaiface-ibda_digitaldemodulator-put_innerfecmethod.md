# IBDA_DigitalDemodulator::put_InnerFECMethod

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_InnerFECMethod** method specifies the inner forward error correction method for the signal.

## Parameters

### `pFECMethod` [in]

Pointer to an [FECMethod](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/fecmethod) variable that specifies the inner forward error correction method.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_DigitalDemodulator Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_digitaldemodulator)

[IBDA_DigitalDemodulator::get_InnerFECMethod](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_digitaldemodulator-get_innerfecmethod)

[IBDA_DigitalDemodulator::put_OuterFECMethod](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_digitaldemodulator-put_outerfecmethod)