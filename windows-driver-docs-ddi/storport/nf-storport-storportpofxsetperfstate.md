## Description

**StorPortPoFxSetPerfState** sets a component's P-state (performance or "perf" state).

## Parameters

### `HwDeviceExtension`

Pointer to the miniport's device extension.

### `Address`

Address of the device being registered. Currently only adapters are supported, so **Address** must be NULL.

### `Component`

The index that identifies the component whose P-states will be managed. This parameter is an index into the **Components**array in the [**STOR_POFX_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device_v3) structure that the miniport used to register the device for Storport PoFx support. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Flags`

Currently must be set to NULL.

### `SetIndex`

The index of a previously registered perf set.

### `State`

If the perf set contains discrete P-States, this should be an index value. If the perf set is a range, this should be a value within that range.

### `Context`

An arbitrary context that will be passed to the perf set change callback.

## Return value

**StorPortPoFxSetPerfState** returns STOR_STATUS_SUCCESS upon successful completion or if runtime power has been disabled, or an error code such as one of the following:

| Error code | Meaning |
| ---------- | ------- |
| STOR_STATUS_INVALID_PARAMETER | One of the parameters is invalid; for example, **Address** or **Flags** are not NULL. |
| STOR_STATUS_UNSUCCESSFUL | The adapter isn't registered for idle detection. |

## Remarks

## See also