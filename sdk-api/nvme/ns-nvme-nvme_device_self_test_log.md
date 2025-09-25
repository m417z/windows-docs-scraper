# NVME_DEVICE_SELF_TEST_LOG structure

## Description

Contains fields that specify the information in a Device Self Test log page that describes the status, completion percentage, and results of a device self-test.

This structure is returned by the Get Log Page command. For more information, see [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page).

## Members

### `CurrentOperation`

A **CurrentOperation** structure containing fields that describe the current Device Self-Test operation.

### `CurrentOperation.Status`

Indicates the status of the current Device Self-Test operation.

### `CurrentOperation.Reserved`

A reserved field in the **CurrentOperation** structure.

### `CurrentCompletion`

A **CurrentCompletion** structure containing fields that describe the completion of a Device Self-Test operation.

### `CurrentCompletion.CompletePercent`

Indicates the percentage of completion of the Device Self-Test operation. This field is valid if the **CurrentOperation.Status** field is non-zero.

### `CurrentCompletion.Reserved`

A reserved field in the **CurrentCompletion** structure.

### `Reserved`

A reserved field.

### `ResultData`

An array of 20 [NVME_DEVICE_SELF_TEST_RESULT_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_device_self_test_result_data) structures that contain result data for the last 20 Device Self-Test operations, sorted in order from the most recent to the oldest available.

## Remarks

## See also