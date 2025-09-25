# WdfTimerCreate function

## Description

*[Applies to KMDF and UMDF]*

The **WdfTimerCreate** method creates a framework timer object.

## Parameters

### `Config` [in]

A pointer to a [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure.

### `Attributes` [in]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for the new timer object.

### `Timer` [out]

A pointer to a location that receives a handle to the new framework timer object.

## Return value

**WdfTimerCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
|-------------|-------------|
| **STATUS_WDF_PARENT_NOT_SPECIFIED** | The *Attributes* parameter was **NULL**, or the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that *Attributes* specifies was **NULL**. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INVALID_DEVICE_REQUEST** | The **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure did not reference a framework device object or an object whose chain of parents leads to a framework device object. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |
| **STATUS_WDF_INCOMPATIBLE_EXECUTION_LEVEL** | The **AutomaticSerialization** member of the [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure was set to **TRUE**, but the parent device object's [execution level](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_execution_level) was set to **WdfExecutionLevelPassive**. |

For a list of other return values that the **WdfTimerCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

When your driver calls **WdfTimerCreate**, it must supply a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and must specify a parent object in the structure's **ParentObject** member. The parent object can be a framework device object or any object whose chain of parents leads to a framework device object. The framework will delete the timer object when it deletes the device object.

After creating a timer object, the driver must call [WdfTimerStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimerstart) to start the timer's clock regardless of whether the timer is periodic or not.

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the framework timer object, note that the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

For more information about framework timer objects, see [Using Timers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-timers).

### Examples

The following code example initializes a [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure and a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and then calls **WdfTimerCreate**.

```cpp
WDF_TIMER_CONFIG  timerConfig;
WDF_OBJECT_ATTRIBUTES  timerAttributes;
WDFTIMER  timerHandle;
NTSTATUS  status;

WDF_TIMER_CONFIG_INIT(
                      &timerConfig,
                      MyEvtTimerFunc
                      );

// Consider allowing a tolerance for the due time and period.
// For more information on no-wake timers and timer coalescing, see:
// https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/no-wake-timers
timerConfig.TolerableDelay = 10;

WDF_OBJECT_ATTRIBUTES_INIT(&timerAttributes);
timerAttributes.ParentObject = DeviceHandle;

status = WdfTimerCreate(
                        &timerConfig,
                        &timerAttributes,
                        &timerHandle
                        );

if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

- [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)
- [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)
- [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config)
- [WDF_TIMER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdf_timer_config_init)
- [WdfTimerStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimerstart)