# IESValueUpdatedEvent::GetValueNames

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

For a name-value pair in the PBDA General Purpose Name-Value Service, gets the name for the value that has been updated. PBDA Media Sink Devices (MSDs) get this name from **ValueUpdated** events fired by Media Transform Devices (MTDs) that implement the [IESValueUpdatedEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesvalueupdatedevent) interface.

## Parameters

### `pbstrNames` [out, retval]

Pointer to a buffer that gets the name that has been updated. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESValueUpdatedEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesvalueupdatedevent)