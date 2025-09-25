# IESEventServiceConfiguration::RemoveParent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Removes the parent of the current event service. Once an event service has removed a parent, the parent can no longer pass advise events to the child event service for handling.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice)

[IESEventServiceConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventserviceconfiguration)