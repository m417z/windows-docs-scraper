# ITuner::put_PreferredComponentTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_PreferredComponentTypes** method sets the collection of **ComponentType** objects used for default component selection.

## Parameters

### `ComponentTypes` [in]

Pointer to an [IComponentTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttypes) interface that contains the collection of ComponentType objects.

## Return value

When the method is successful, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications create a list of preferred component types by instantiating an empty **ComponentTypes** collection, filling it, then submitting it to the Tuner using **put_PreferredComponentTypes**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)