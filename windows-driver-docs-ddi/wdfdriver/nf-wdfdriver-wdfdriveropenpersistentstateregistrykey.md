## Description

Drivers should use **WdfDriverOpenPersistentStateRegistryKey** to write driver wide persistent information to the registry.

## Parameters

### `Driver` [in]

A handle to the driver's framework driver object that the driver obtained from a previous call to [**WdfDriverCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [**WdfGetDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver).

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) typed value that specifies an access mask for the registry key.
A KMDF driver typically requests **KEY_READ**, **KEY_WRITE**, or **KEY_READ** | **KEY_WRITE**.
If you are writing a UMDF driver, use **KEY_READ** or **KEY_READ** | **KEY_SET_VALUE**.
As a best practice, ask for only the types of access that your driver needs.

### `KeyAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the framework registry-key object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.
### `Key` [out]

A pointer to a location that receives a handle to a framework registry-key object.

## Return value

Refer to [**WdfDriverOpenParametersRegistryKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey).

## Remarks

The `Parameters` key is for *immutable* settings provided in the INF file. To access those settings, use [**WdfDriverOpenParametersRegistryKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey). The key returned from this API is for settings written at runtime.

## See also

[**WdfDriverOpenParametersRegistryKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey)

[**IoOpenDriverRegistryKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendriverregistrykey)

[**DRIVER_REGKEY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-driver_regkey_type)