# NVME_CDW11_FEATURE_ARBITRATION structure

## Description

Contains values for the Arbitration Feature that controls command arbitration.

The values from this structure are used in the **Arbitration** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.AB`

Specifies the maximum number of commands that the controller may launch at one time from a particular Submission Queue.

The value for this field is specified as 2^n. A value of `111b` indicates no limit. The possible values for this field are 1, 2, 4, 8, 16, 32, 64, or no limit.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.LPW`

Specifies the Low Priority Weight (LPW). The number of commands that may be executed from the low priority service class in each arbitration round. This is a 0’s based value.

### `DUMMYSTRUCTNAME.MPW`

Specifies the Medium Priority Weight (MPW). The number of commands that may be executed from the medium priority service class in each arbitration round. This is a 0’s based value.

### `DUMMYSTRUCTNAME.HPW`

Specifies the High Priority Weight (HPW). The number of commands that may be executed from the high priority service class in each arbitration round. This is a 0’s based value.

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)