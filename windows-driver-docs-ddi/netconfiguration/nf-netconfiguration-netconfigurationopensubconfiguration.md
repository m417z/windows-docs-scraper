# NetConfigurationOpenSubConfiguration function

## Description

Opens a sub configuration of a specified adapter configuration object.

## Parameters

### `Configuration` [_In_]

A handle to an adapter configuration object opened in a prior call to [NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration) or **NetConfigurationOpenSubConfiguration**.

### `SubConfigurationName` [_In_]

A pointer to a string specifying the name of the sub configuration to open.

### `SubConfigurationAttributes` [_In_opt_]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new configuration object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `SubConfiguration` [_Out_]

A pointer to a location that receives a handle to the new sub configuration object.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

If the client provides a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes), it specifies **NULL** for **ParentObject**. By default, the sub configuration is parented to the existing adapter configuration object.

The client driver closes the sub configuration by calling [NetConfigurationClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationclose) with either the sub configuration object or the parent adapter configuration object.

## See also

[NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration)