# wiasQueueEvent function

## Description

The **wiasQueueEvent** function informs the service that the device generated an event.

## Parameters

### `bstrDeviceId` [in]

Specifies the device ID. This is the value passed to the minidriver in the call to the [IWiaMiniDrv::drvInitializeWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvinitializewia) method.

### `pEventGUID` [in]

Pointer to a buffer that contains the GUID for the event.

### `bstrFullItemName` [in, optional]

Specifies the full item name, including path information.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This method should be used whenever the device must signal that an event of some type occurred. The device does this by placing the event on the event queue. For example, when a camera takes a new picture, it should generate a WIA_EVENT_ITEM_CREATED event after adding a new driver item to its tree. The camera can place this event on the event queue in this way:

```cpp
hr = wiasQueueEvent(bstrMyDeviceId,
                    &WIA_EVENT_ITEM_CREATED,
                    bstrDescriptionString);
```

See the Windows SDK documentation for a complete list of WIA event identifiers.

## See also

[IWiaMiniDrv::drvInitializeWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvinitializewia)