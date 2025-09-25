# ITuner::Validate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Validate** method returns a value indicating that the tune request can be carried out.

## Parameters

### `TuneRequest` [in]

Pointer to the tune request object.

## Return value

When the method is successful, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Network Provider will first query for its preferred tune request interface(s). If any are found, the Network Provider will validate that the tune request could be carried out. If none are available, it will then query for its preferred tuning space interface(s). If any are found, the Network Provider will validate that it could configure itself for the given tuning space.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)