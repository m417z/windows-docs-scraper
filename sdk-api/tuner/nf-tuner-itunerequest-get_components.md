# ITuneRequest::get_Components

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Components** method retrieves the components contained in this tune request.

## Parameters

### `Components` [out]

Receives an [IComponents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponents) interface pointer. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

A tune request always contains a collection of components, but the collection can be empty. If the component information is present in the transport stream tables, a Guide Store loader can obtain the information from the TIF and include it in the tune request at the time it creates it.

If the method succeeds, the [IComponents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponents) interface has an outstanding reference count. The caller must release the interface.

After a tune request is submitted to the Network Provider filter, the Network Provider updates the component lists in the tune request. You can get the updated component list by calling [ITuner::get_TuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituner-get_tunerequest) on the Network Provider, and then calling **get_Components** on the returned tune request. (The original tune request that was submitted to the Network Provider does not get updated, because the Network Provider creates an internal copy of the tune request. Therefore, you have to call **get_TuneRequest** to get the updated component list.)

## See also

[ITuneRequest Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest)