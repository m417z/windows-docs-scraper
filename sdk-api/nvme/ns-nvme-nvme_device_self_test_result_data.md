# NVME_DEVICE_SELF_TEST_RESULT_DATA structure

## Description

Contains data about the results of a Device Self-Test operation.

This structure is used in the **ResultData** field of the [NVME_DEVICE_SELF_TEST_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_device_self_test_log) structure.

## Members

### `Status`

A **Status** structure containing fields that describe the status of a Device Self-Test operation.

### `Status.Result`

Indicates the result of the Device Self-Test operation.

### `Status.CodeValue`

Indicates the Self-Test code value that was specified in the command.

### `SegmentNumber`

Indicates the first segment in which a failure occurred during the Device Self-Test operation.

### `ValidDiagnostics`

A **ValidDiagnostics** structure containing fields that indicate the validity of certain parameters in a Device Self-Test operation.

### `ValidDiagnostics.NSIDValid`

A **ValidDiagnostics** field that indicates whether the contents of the Namespace Identifier (**NSID**) field is valid.

When this value is set to `1`, the contents of the **NSID** field are valid.

### `ValidDiagnostics.FLBAValid`

A **ValidDiagnostics** field that indicates whether the contents of the Failing Logical Block Address (**FLBA**) field is valid.

When this value is set to `1`, the contents of the **FLBA** field are valid.

### `ValidDiagnostics.SCTValid`

A **ValidDiagnostics** field that indicates whether the contents of the Status Code Type (**StatusCodeType**) field is valid.

When this value is set to `1`, the contents of the **StatusCodeType** field is valid.

### `ValidDiagnostics.SCValid`

A **ValidDiagnostics** field that indicates whether the contents of the Status Code (**StatusCode**) field is valid.

When this value is set to `1`, the contents of the **StatusCode** field is valid.

### `ValidDiagnostics.Reserved`

A reserved field in the **ValidDiagnostics** structure.

### `Reserved`

A reserved field.

### `POH`

Indicates the number of Power On Hours (POH) when the test operation was completed or aborted.

### `NSID`

Contains the Namespace Identifier (NSID). This field is only valid if **NSIDValid** is set to `1`.

### `FailingLBA`

The Logical Block Address (LBA) which caused the test to fail. This field is only valid if **FLBAValid** is set to `1`.

### `StatusCodeType`

A Status Code Type (**StatusCodeType**) structure containing fields that contain information about errors and conditions.

### `StatusCodeType.AdditionalInfo`

A **StatusCodeType** field that contains additional information related to errors and conditions of the Device Self-Test operation based on the [Status Code Type](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_types).

This field is only valid if **SCTValid** is set to `1`.

### `StatusCodeType.Reserved`

A reserved field in the **StatusCodeType** structure.

### `StatusCode`

A **StatusCodeType** field that contains additional information related to errors and conditions of the Device Self-Test operation based on the Status Code.

This field is only valid if **SCValid** is set to `1`.

### `VendorSpecific`

A vendor specific field.

## Remarks

## See also