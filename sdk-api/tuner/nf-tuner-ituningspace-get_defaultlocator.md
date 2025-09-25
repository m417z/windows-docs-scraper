# ITuningSpace::get_DefaultLocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_DefaultLocator** method retrieves the default locator for this tuning space.

## Parameters

### `LocatorVal` [out]

Address of a variable that receives a pointer to [ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator) interface. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The tuning space might not have a default locator. It is the application's responsibility to provide a default locator for the tuning space if needed.

If the tuning space does not have a default locator, this method succeeds but returns the value **NULL** in the *ppLocatorVal* parameter. Check for a **NULL** value before attempting to dereference the pointer.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)

[ITuningSpace::put_DefaultLocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspace-put_defaultlocator)