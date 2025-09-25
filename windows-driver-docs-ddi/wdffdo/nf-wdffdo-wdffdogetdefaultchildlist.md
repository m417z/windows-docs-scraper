# WdfFdoGetDefaultChildList function

## Description

[Applies to KMDF only]

The **WdfFdoGetDefaultChildList** method returns a handle to a specified device's default child list.

## Parameters

### `Fdo` [in]

A handle to a framework device object.

## Return value

If the operation succeeds, **WdfFdoGetDefaultChildList** returns a handle to the default child list that is associated with the device that is specified by *Fdo*. Otherwise the method returns **NULL**.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Before calling **WdfFdoGetDefaultChildList**, your driver must call [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) to configure the default child list. Otherwise, **WdfFdoGetDefaultChildList** returns **NULL**.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example obtains a handle to a device's default child list.

```cpp
WDFCHILDLIST  list;

list = WdfFdoGetDefaultChildList(Device);
```

## See also

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)