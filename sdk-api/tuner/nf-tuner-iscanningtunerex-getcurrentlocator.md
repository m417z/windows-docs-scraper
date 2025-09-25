# IScanningTunerEx::GetCurrentLocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista and later.

The **GetCurrentLocator** method retrieves the current locator object.

## Parameters

### `pILocator` [out]

Receives a pointer to the [ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator) interface of the locator object. The caller must release the interface.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[IScanningTunerEx Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtunerex)