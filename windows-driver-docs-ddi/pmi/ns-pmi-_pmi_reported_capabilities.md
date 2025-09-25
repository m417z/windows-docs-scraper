# _PMI_REPORTED_CAPABILITIES structure

## Description

The PMI_REPORTED_CAPABILITIES structure contains information about the type of power metering and budgeting capabilities a power meter supports. Additionally, this structure contains asset information about the power meter itself.

## Members

### `Flags`

A bitmask that specifies the supported capabilities of the power meter. The following flags define the range of values for this member:

#### PMI_CAPABILITIES_SUPPORT_MEASUREMENT

This bit is set if the power meter supports power measurement.

#### PMI_CAPABILITIES_SUPPORT_THRESHOLDS

This bit is set if the power meter supports power thresholds.

#### PMI_CAPABILITIES_SUPPORT_BUDGETING

This bit is set if the power meter supports power budgeting.

#### PMI_CAPABILITIES_DISCHARGE_ONLY

This bit is set if the power meter reports data only when the power supply is discharging. This is typically the case on mobile battery systems or some uninterruptible power supplies (UPSs).

### `MeasurementUnit`

A [PMI_MEASUREMENT_UNIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_measurement_unit) enumeration value that specifies the measurement unit.

**Note** Beginning with Windows 7, Windows Server 2008 R2, only measurement units of milliwatts (mW) are supported.

### `MeasurementType`

A [PMI_MEASUREMENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_measurement_type) enumeration value that specifies the measurement type, such as whether input or output power is measured.

### `Accuracy`

A value, in units of thousandths of a percent, that specifies the reported accuracy of the power meter. For example, a value of 1,000 corresponds to a one percent accuracy rating.

### `SamplingPeriod`

A value, in units of milliseconds, that specifies the current averaging period.

### `MinimumAverageInterval`

A value, in units of milliseconds, that specifies the minimum averaging interval.

### `MaximumAverageInterval`

A value, in units of milliseconds, that specifies the maximum averaging interval.

### `Hysteresis`

A value, in units of milliseconds, that specifies the hysteresis value. This value indicates the margin that is built around the threshold and budget events. This value prevents the trigger of unnecessary events when the reading fluctuates very close to one of the thresholds.

### `Writeable`

A Boolean value that indicates whether the budgeting information is read/write (TRUE) or read-only (FALSE).

### `MinBudget`

A value, in units of watts, that specifies the minimum supported power budget.

### `MaxBudget`

A value, in units of watts, that specifies the maximum supported power budget.

### `ModelNumber`

A null-terminated, Unicode string that contains the model number of the power meter.

### `SerialNumber`

A null-terminated, Unicode string that contains the serial number of the power meter.

### `OEMInformation`

A null-terminated, Unicode string that contains descriptive information about the power meter. This information is specific to the implementation by the original OEM.

## Remarks

The PMI_REPORTED_CAPABILITIES structure contains the following information about a power meter:

* The power meter's measurement capabilities.
* The power meter's budget capabilities, which includes whether the budget configuration can be changed.
* The power meter's asset information. This information is defined by the OEM for the power meter.

The PMI_REPORTED_CAPABILITIES structure is returned through an [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) I/O control (IOCTL) query request. The input data for this query request is set to the [PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type) enumerator value of **PmiReportedCapabilities**..

If the query request completes successfully, the request returns a [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure. The **Capabilities** member of this structure is formatted as a PMI_REPORTED_CAPABILITIES structure.

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities)

[PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type)