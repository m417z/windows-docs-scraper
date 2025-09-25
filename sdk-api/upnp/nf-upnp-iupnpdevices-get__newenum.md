# IUPnPDevices::get__NewEnum

## Description

The
**_NewEnum** property specifies either the [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) or [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown) enumerator interface for the collection.

## Parameters

### `ppunk` [out]

Receives a reference to the enumerator interface.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

This property is not visible in Visual Basic; use the **for...each...next** programming construct instead.

## See also

[IUPnPDevices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevices)