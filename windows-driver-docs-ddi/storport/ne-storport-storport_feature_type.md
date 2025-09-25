# STORPORT_FEATURE_TYPE enumeration

## Description

The **STORPORT_FEATURE_TYPE** enumeration identifies a Storport feature supported by a miniport.

## Constants

### `StorportFeatureBusTypeUnitControl`

Indicates whether the **ScsiUnitQueryBusType** control operation is supported.

### `StorportFeatureFruIdUnitControl`

Indicates whether the **ScsiUnitQueryFruId** control operation is supported.

### `StorportFeatureFruIdAdapterControl`

Indicates whether the **ScsiAdapterQueryFruId** control operation is supported.

### `StorportFeatureSetEventLoggingAdapterControl`

Indicates whether the **ScsiAdapterSetEventLogging** control operation is supported.

### `StorportFeatureReportInternalDataUnitControl`

Indicates whether the **ScsiUnitReportInternalData** control operation is supported.

### `StorportFeatureReportInternalDataAdapterControl`

Indicates whether the **ScsiAdapterReportInternalData** control operation is supported.

### `StorportFeatureResetBusSynchronous`

Indicates whether the **ScsiAdapterResetBusSynchronous** control operation is supported.

### `StorportFeaturePostHwInitialize`

Indicates whether the **ScsiAdapterPostHwInitialize** control operation is supported.

### `StorportFeaturePrepareEarlyDumpData`

Indicates whether the **ScsiAdapterPrepareEarlyDumpData** control operation is supported.

### `StorportFeatureRestoreEarlyDumpData`

Indicates whether the **ScsiAdapterRestoreEarlyDumpData** control operation is supported.

### `StorportFeatureKsrAdapterPowerDownOptimization`

Reserved for internal use. Do not use.

### `StorportFeatureKsrUnitPowerDownOptimization`

Reserved for internal use. Do not use.

### `StorportFeaturePreparePLDR`

Indicates whether the **ScsiAdapterPreparePLDR** control operation is supported.

### `StorportFeatureNvmeofAdapterOperation`

Indicates whether the **ScsiNvmeofAdapterOperation** control operation is supported.

### `StorportFeatureReserved1`

Reserved, do not use.

### `StorportFeatureMax`

Max value for this enumeration.

## Remarks

A miniport provides an array of **STORPORT_FEATURE_TYPE** values when it calls [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist), where each value indicates whether the miniport provides support for a control operation.

Storport specifies the control type when it calls a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine.

## See also

[**SCSI_ADAPTER_CONTROL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_adapter_control_type)

[**STOR_SET_EVENT_LOGGING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_set_event_logging)

[**STOR_FRU_ID_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_fru_id_description)

[**STOR_UNIT_CONTROL_QUERY_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_unit_control_query_bus_type)

[**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist)