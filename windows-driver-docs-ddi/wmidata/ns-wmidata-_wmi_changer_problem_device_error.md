# _WMI_CHANGER_PROBLEM_DEVICE_ERROR structure

## Description

When the [ChangerPerformDiagnostics](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerperformdiagnostics) routine performs diagnostic tests on a changer device it returns the results in a WMI_CHANGER_PROBLEM_DEVICE_ERROR structure.

## Members

### `ChangerProblemType`

Contains one of the enumeration values defined for the [CHANGER_DEVICE_PROBLEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ne-ntddchgr-_changer_device_problem_type) enumeration data type. The minidriver sets **ChangerProblemType** to the appropriate enumerator value.

## Syntax

```cpp
typedef struct _WMI_CHANGER_PROBLEM_DEVICE_ERROR {
  ULONG ChangerProblemType;
} WMI_CHANGER_PROBLEM_DEVICE_ERROR, *PWMI_CHANGER_PROBLEM_DEVICE_ERROR;
```

## See also

[CHANGER_DEVICE_PROBLEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ne-ntddchgr-_changer_device_problem_type)

[ChangerPerformDiagnostics](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerperformdiagnostics)