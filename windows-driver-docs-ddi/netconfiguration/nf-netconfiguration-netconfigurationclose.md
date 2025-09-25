# NetConfigurationClose function

## Description

Releases the handle to the registry key that is associated with an adapter configuration object and then deletes the adapter configuration object.

## Parameters

### `Configuration` [_In_]

A handle to an adapter configuration object opened in a prior call to [NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration) or [NetConfigurationOpenSubConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationopensubconfiguration).

## Remarks

**NetConfigurationClose** is an alias of [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete). Because the configuration object, like all NetAdapterCx objects, is a WDF object, you can use [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) interchangeably.

## See also

[NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration)

[NetConfigurationOpenSubConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationopensubconfiguration)