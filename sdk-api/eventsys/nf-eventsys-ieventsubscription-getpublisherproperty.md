# IEventSubscription::GetPublisherProperty

## Description

Retrieves the value of a property stored in the property bag to define publisher context.

## Parameters

### `bstrPropertyName` [in]

The name of the requested property.

### `propertyValue` [out, retval]

The value of the requested property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Publisher filters should call this method to obtain filter properties stored by the subscription builder.

## See also

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[PublisherID](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-get_publisherid)