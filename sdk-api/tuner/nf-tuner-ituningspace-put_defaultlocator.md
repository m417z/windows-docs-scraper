# ITuningSpace::put_DefaultLocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_DefaultLocator** method sets the default locator for this tuning space.

## Parameters

### `LocatorVal` [in]

Pointer to the [ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator) interface of the locator object.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

See [ITuningSpace::get_DefaultLocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspace-get_defaultlocator) for more information about the default locator.

For DVB tuning spaces, the sytem type (cable, terrestrial, or satellite) of the tuning space must match the locator object. Otherwise, the method returns DISP_E_TYPEMISMATCH. For more information, see [IDVBTuningSpace::put_SystemType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-idvbtuningspace-put_systemtype).

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)