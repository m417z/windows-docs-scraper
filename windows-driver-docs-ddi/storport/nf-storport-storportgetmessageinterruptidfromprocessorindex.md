## Description

A Storport miniport can call **StorPortGetMessageInterruptIDFromProcessorIndex** to get the message interrupt ID of the specified processor index.

## Parameters

### `HwDeviceExtension`

[in] Pointer to the miniport's device extension.

### `ProcessorIndex`

[in] A system-wide processor index. If a multiprocessor system contains a total of *n* logical processors, valid processor indexes range from 0 to *n*-1.

### `MessageInterruptID`

[out] Pointer to a ULONG value in which the message interrupt ID of **ProcessorIndex** is written.

## Return value

**StorPortGetMessageInterruptIDFromProcessorIndex** returns STOR_STATUS_SUCCESS if the miniport data is successfully reported. Possible error return values include the following.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_INVALID_PARAMETER | There is an invalid parameter, such as an invalid **ProcessorIndex** value. |
| STOR_STATUS_UNSUCCESSFUL | An error occurred for internal reasons. |

## Remarks

See the *Remarks* section of [**KeGetProcessorNumberFromIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex) for details.