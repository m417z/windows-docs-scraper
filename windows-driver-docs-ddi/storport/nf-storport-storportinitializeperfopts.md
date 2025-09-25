# StorPortInitializePerfOpts function

## Description

The **StorPortInitializePerfOpts** function initializes the performance optimizations that both the miniport driver and the Storport driver support using a [PERF_CONFIGURATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_perf_configuration_data) structure.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA). This parameter must not be **NULL**.

### `Query` [in]

If set to **TRUE**, Storport will set the flags in *PerfConfigData* corresponding to the optimizations Storport supports. If set to **FALSE**, Storport will initialize the optimizations specified by the flags in *PerfConfigData*.

### `PerfConfigData` [in, out]

A pointer to a PERF_CONFIGURATION_DATA structure that is supplied by the miniport driver. This parameter must not be **NULL**.

## Return value

StorPortInitializePerfOpts returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the performance optimization settings have been applied.<br><br>Or if *Query* is set to **TRUE**, the **Flags** member of the structure pointed to by *PerfConfigData* contains the supported flags. |
| **STOR_STATUS_UNSUCCESSFUL** | The miniport driver set a flag in *PerfConfigData* that Storport did not recognize, or the miniport driver has called this routine from outside the miniport-driver-supplied [HwStorInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routine. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Unable to allocate internal structures to support the requested optimizations. |
| **STOR_STATUS_INVALID_PARAMETER** | Either the *HwDeviceExtension* parameter or the *PerfConfigData* parameter was **NULL**. |

## Remarks

 The miniport driver can call **StorPortInitializePerfOpts** only during the miniport-supplied [HwStorInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routine or [HwStorPassiveInitializeRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine) routine.

Available performance optimizations depend on the version of [PERF_CONFIGURATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_perf_configuration_data). Setting the **Version** member to **STOR_PERF_VERSION** will allow all supported optimizations to be selected.

## See also

[PERF_CONFIGURATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_perf_configuration_data)