# BCLASS_SET_INFORMATION_CALLBACK callback function

## Description

*BatteryMiniSetInformation* requests that a battery enter the charging or discharging state, or sets a critical bias value for the battery.

## Parameters

### `Context` [in]

A pointer to the context area allocated by the miniclass driver for the battery device.

### `BatteryTag` [in]

A battery tag value previously returned by *BatteryMiniQueryTag*.

### `Level` [in]

One of the following values: **BatteryCriticalBias**, **BatteryCharge**, or **BatteryDischarge.**

### `Buffer` [in]

The critical bias adjustment in milliwatts if *Level* is **BatteryCriticalBias**. Not used for other values of *Level*.

## Return value

*BatteryMiniSetInformation* returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. |
| **STATUS_NO_SUCH_DEVICE** | No battery is present. |
| **STATUS_NOT_SUPPORTED** | The specified battery does not support the requested operation. |
| **STATUS_UNSUCCESSFUL** | The operation failed. |

## Remarks

The battery class driver calls *BatteryMiniSetInformation* to request that a battery start to charge or discharge. It can also call this routine to set a critical bias value.

With a smart battery charger/selector, the class driver specifies **BatteryCharge** to select a battery to charge, possibly discontinuing the charging of another battery.

The class driver specifies **BatteryDischarge** to indicate which battery should power the system.

The critical bias adjustment is analogous to the reserve capacity of the gas tank in an automobile. It represents the remaining charge when the battery capacity is reported as zero. Although the class driver does not change the critical bias value in normal use, this field is provided in the interface as a maintenance feature. Not all batteries can maintain a critical bias setting. Miniclass drivers for such batteries should return STATUS_NOT_SUPPORTED.