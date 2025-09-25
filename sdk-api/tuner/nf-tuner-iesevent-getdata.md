# IESEvent::GetData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets data from an event that is derived from the [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) interface. This method gets a byte array that contains the data in an **IESEvent** object, which is passed in a call to [IESEventService::FireESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventservice-fireesevent).

## Parameters

### `pbData` [out, retval]

Pointer to **SAFEARRAY** that receives the event data.
The caller is responsible for freeing the **SAFEARRAY**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FireESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventservice-fireesevent)

[IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent)