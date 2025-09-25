# ITraceDataProviderCollection::get__NewEnum

## Description

Retrieves an interface to the enumeration.

This property is read-only.

## Parameters

## Remarks

 C++ programmers use this property.

The enumeration is a snapshot of the collection at the time of the call.

The items of the enumeration are variants whose type is VT_UNKNOWN. To query for the [ITraceDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedatacollector) interface, use the **punkVal** member of the variant.

## See also

[ITraceDataProviderCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovidercollection)