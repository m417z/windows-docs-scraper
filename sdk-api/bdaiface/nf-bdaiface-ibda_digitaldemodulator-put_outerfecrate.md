# IBDA_DigitalDemodulator::put_OuterFECRate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_OuterFECRate** method specifies the outer forward error correction rate for the signal.

## Parameters

### `pFECRate` [in]

Pointer to a [BinaryConvolutionCodeRate](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/binaryconvolutioncoderate) variable that specifies the FEC rate.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_DigitalDemodulator Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_digitaldemodulator)

[IBDA_DigitalDemodulator::get_OuterFECRate](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_digitaldemodulator-get_outerfecrate)

[IBDA_DigitalDemodulator::put_InnerFECRate](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_digitaldemodulator-put_innerfecrate)