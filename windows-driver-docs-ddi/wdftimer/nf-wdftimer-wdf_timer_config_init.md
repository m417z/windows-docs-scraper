# WDF_TIMER_CONFIG_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_TIMER_CONFIG_INIT** function initializes a [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure for a timer that will use a single due time.

## Parameters

### `Config` [in]

A pointer to a [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure.

### `EvtTimerFunc` [in]

A pointer to a driver-supplied [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function.

## Remarks

The **WDF_TIMER_CONFIG_INIT** function zeros the specified [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure. Then it sets the structure's **Size** member, stores the *EvtTimerFunc* pointer, sets the **Period** member and the **TolerableDelay** member to zero, and sets the **AutomaticSerialization** member to **TRUE**.

#### Examples

For a code example that uses **WDF_TIMER_CONFIG_INIT**, see [WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate).

## See also

[EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer)

[WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config)

[WDF_TIMER_CONFIG_INIT_PERIODIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdf_timer_config_init_periodic)