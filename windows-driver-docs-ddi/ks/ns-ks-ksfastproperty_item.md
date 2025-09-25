# KSFASTPROPERTY_ITEM structure

## Description

The KSFASTPROPERTY_ITEM structure is used with items for fast I/O dispatching.

## Members

### `PropertyId`

Specifies the identifier of the specific property within the set.

### `GetPropertyHandler`

Points to a driver-supplied [KStrFastHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfasthandler) routine that specifies the fast handler for retrieving the property. If this is **NULL**, the property cannot be read with a fast handler.

### `GetSupported`

A boolean value that indicates if the driver has supplied a get property handler.

### `SetPropertyHandler`

Points to a driver-supplied [KStrFastHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfasthandler) routine that specifies the fast handler for setting the property. If this is **NULL**, the property cannot be set with a fast handler.

### `SetSupported`

A boolean value that indicates if the driver has supplied a set property handler.

### `Reserved`

Reserved and set to zero.

## See also

[KStrFastHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfasthandler)