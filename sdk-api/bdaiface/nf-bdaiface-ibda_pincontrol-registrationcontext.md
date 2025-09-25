# IBDA_PinControl::RegistrationContext

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **RegistrationContext** method retrieves the registration context of a particular pin.

## Parameters

### `pulRegistrationCtx` [out]

Pointer that receives the registration context.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The registration context uniquely identifies an instance of a particular pin. A Network Provider does not modify this value; it simply retains it in order to keep track of the pins in the graph.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_PinControl Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_pincontrol)