# ITuningSpace::get_DefaultPreferredComponentTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_DefaultPreferredComponentTypes** method returns a list of the default preferred component types for this tuning space.

## Parameters

### `ComponentTypes` [out]

Address of a variable that receives an [IComponentTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttypes) interface pointer. Use this interface to enumerate the component types. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

A component is a stream within the program. An example of a preferred component type would be an audio stream in English. When multiple components are available, the Tuner attempts to play the preferred ones first.

If the tuning space does not have any default preferred types, this method succeeds but returns the value **NULL** in the *ppComponentTypes* parameter. Check for a **NULL** value before attempting to dereference the pointer.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)