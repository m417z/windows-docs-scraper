# ITuner::get_PreferredComponentTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_PreferredComponentTypes** method gets the collection of ComponentType objects used for default component selection.

## Parameters

### `ComponentTypes` [out]

Address of an [IComponentTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttypes) interface pointer that receives the collection of ComponentType objects.

## Return value

When the method is successful, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a program ends, there may be a new set of stream components available, so at that time the tuner will automatically examine the list of preferred component types and select a component based on that list. If no list is available, the tuner will make a selection based on other factors. Applications call this method simply to examine the current list.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)