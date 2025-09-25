# EVT_IDD_CX_MONITOR_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS callback function

## Description

**EVT_IDD_CX_MONITOR_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS** is called by the OS to set the signing key and sequence number.

## Parameters

### `OpmCxtObject` [in]

The object for the OPM context whose signing key and sequence number will be set.

### `pInArgs` [in]

Input arguments used by **EVT_IDD_CX_MONITOR_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.