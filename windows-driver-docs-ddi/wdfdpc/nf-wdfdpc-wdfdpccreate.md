# WdfDpcCreate function

## Description

[Applies to KMDF only]

The **WdfDpcCreate** method creates a framework DPC object and registers an [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function.

## Parameters

### `Config` [in]

A pointer to a caller-allocated [WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config) structure.

### `Attributes` [in]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the new DPC object.

### `Dpc` [out]

A pointer to a location that receives a handle to the new framework DPC object.

## Return value

**WdfDpcCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | A DPC object could not be allocated. |
| **STATUS_WDF_PARENT_NOT_SPECIFIED** | A parent object was not specified in the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. |
| **STATUS_INVALID_DEVICE_REQUEST** | The **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure does not reference a framework device object or an object whose chain of parents leads to a framework device object. |
| **STATUS_WDF_INCOMPATIBLE_EXECUTION_LEVEL** | The **AutomaticSerialization** member of the [WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config) structure is set to **TRUE**, but the parent object's [execution level](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_execution_level) is set to **WdfExecutionLevelPassive**. |

For a list of other return values that the **WdfDpcCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A driver typically calls **WdfDpcCreate** from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

When a driver creates a DPC object, it must specify a parent object in the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. The parent object can be a framework device object or any object whose chain of parents leads to a framework device object. The framework will delete the DPC object when it deletes the device object.

Calling **WdfDpcCreate** creates a framework DPC object and registers an [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function. To schedule execution of the callback function, the driver must call [WdfDpcEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcenqueue).

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the framework timer object, note that the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

For more information about using DPC objects, see [Servicing an Interrupt](https://learn.microsoft.com/windows-hardware/drivers/wdf/servicing-an-interrupt).

#### Examples

The following code example initializes a [WDF_DPC_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdf_dpc_config_init) structure and then creates a DPC object.

```cpp
WDF_DPC_CONFIG dpcConfig;
WDF_OBJECT_ATTRIBUTES dpcAttributes;
NTSTATUS status;

WDF_DPC_CONFIG_INIT(
                    &dpcConfig,
                    MyEvtDpcFunc
                    );
dpcConfig.AutomaticSerialization = TRUE;
WDF_OBJECT_ATTRIBUTES_INIT(&dpcAttributes);
dpcAttributes.ParentObject = pDevExt->WdfDevice;
status = WdfDpcCreate(
                      &dpcConfig,
                      &dpcAttributes,
                      &pDevExt->CompleteWriteDpc
                      );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config)

[WDF_DPC_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdf_dpc_config_init)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WdfDpcEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcenqueue)