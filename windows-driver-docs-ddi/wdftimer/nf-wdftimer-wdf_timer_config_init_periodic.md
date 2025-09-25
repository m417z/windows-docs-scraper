# WDF_TIMER_CONFIG_INIT_PERIODIC function

## Description

[Applies to KMDF and UMDF]

The **WDF_TIMER_CONFIG_INIT_PERIODIC** function initializes a [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure for a periodic timer.

## Parameters

### `Config` [in]

A pointer to a [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure.

### `EvtTimerFunc` [in]

A pointer to a driver-supplied [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function.

### `Period` [in]

A time value. For more information about specifying this value, see [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config).

## Remarks

The **WDF_TIMER_CONFIG_INIT_PERIODIC** function zeros the specified [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure. Then it sets the structure's **Size** member, stores the *EvtTimerFunc* pointer and *Period* value, sets the **TolerableDelay** member to zero and sets the **AutomaticSerialization** member to **TRUE**.

#### Examples

The following code example initializes a [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure and a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and then calls [WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate).

```cpp
WDF_TIMER_CONFIG  timerConfig;
WDF_OBJECT_ATTRIBUTES  timerAttributes;
WDFTIMER  timerHandle;
NTSTATUS  Status;

WDF_TIMER_CONFIG_INIT_PERIODIC(
                               &timerConfig,
                               EchoEvtTimerFunc,
                               PERIODIC_TIMER_INTERVAL
                               );

WDF_OBJECT_ATTRIBUTES_INIT(&timerAttributes);
timerAttributes.ParentObject = Queue;

Status = WdfTimerCreate(
                        &timerConfig,
                        &timerAttributes,
                        &timerHandle
                        );
```

## See also

[EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer)

[WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config)

[WDF_TIMER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdf_timer_config_init)