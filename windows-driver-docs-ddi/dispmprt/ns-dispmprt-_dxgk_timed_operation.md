# DXGK_TIMED_OPERATION structure

## Description

The **DXGK_TIMED_OPERATION** structure describes a timed operation, which is used in the [Timed Operation Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation_interface).

## Members

### `Size` [in]

The size, in bytes, of this structure.

### `OwnerTag`

[system] A pointer to the place in the code that started the timed operation.

### `OsHandled`

[system] For system use only.

### `TimeoutTriggered` [out]

A Boolean value that specifies whether the time-out was triggered.

### `Timeout`

[system] For system use only.

### `StartTick`

[system] For system use only.

## Remarks

Display miniport drivers should not change of rely on members that are marked with the [system] designation.

## See also

[**DXGK_TIMED_OPERATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation_interface)