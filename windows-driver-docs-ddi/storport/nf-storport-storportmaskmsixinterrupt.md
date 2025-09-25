## Description

**StorPortMaskMsixInterrupt** masks or unmasks an interrupt in the MSI-X hardware interrupt table.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport's device extension.

### `MessageId` [in]

The index of the table entry in the MSI-X hardware interrupt table.

### `Mask` [in]

Indicates whether to mask (TRUE) or unmask (FALSE) the interrupt.

## Return value

This function returns one of the following status codes.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The specified MSI-X interrupt was successfully enabled/disabled. |
| STOR_STATUS_INVALID_PARAMETER | A parameter is invalid; for example, **MessageId** is not a valid table index value. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal system reasons. |

## Remarks

A miniport can call **StorPortMaskMsixInterrupt** to mask or unmask the specified interrupt in the MSI-X hardware interrupt table. If a table entry is masked, the device does not generate interrupts that correspond to that table entry.