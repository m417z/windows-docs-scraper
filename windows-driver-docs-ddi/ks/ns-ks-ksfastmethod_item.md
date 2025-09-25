# KSFASTMETHOD_ITEM structure

## Description

Drivers provide a structure of type KSFASTMETHOD_ITEM to support fast I/O dispatching.

## Members

### `MethodId`

Contains the identifier of the method and the flags describing the type of method.

### `MethodHandler`

Points to a driver-supplied [KStrFastHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfasthandler) routine for this method.

### `MethodSupported`

Set to **TRUE** if the method is supported, otherwise set to **FALSE**.

## See also

[KSMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item)

[KStrFastHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfasthandler)