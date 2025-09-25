# ITuner::get_TuneRequest

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_TuneRequest** method gets the tune request currently in effect for the Network Provider.

## Parameters

### `TuneRequest` [out]

Address of an [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface pointer that will be set to the returned object.

## Return value

When the method is successful, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

After a tune request is submitted to the Tuner, its Components collection will be filled in. By calling **get_TuneRequest** after tuning to the program, an application can determine which components are currently available for that program, and then use the [IComponent::put_Status](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-icomponent-put_status) method on the Component objects in the collection to activate or inactivate them. This is how an application, for example, changes from an English audio stream to a Spanish audio stream.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)