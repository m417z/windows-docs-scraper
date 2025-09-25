# IBDA_DigitalDemodulator::get_InnerFECMethod

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_InnerFECMethod** method retrieves the inner forward error correction method.

## Parameters

### `pFECMethod` [out]

Pointer that receives an [FECMethod](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/fecmethod) variable.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_DigitalDemodulator Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_digitaldemodulator)

[IBDA_DigitalDemodulator::get_OuterFECMethod](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_digitaldemodulator-get_outerfecmethod)

[IBDA_DigitalDemodulator::put_InnerFECMethod](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_digitaldemodulator-put_innerfecmethod)