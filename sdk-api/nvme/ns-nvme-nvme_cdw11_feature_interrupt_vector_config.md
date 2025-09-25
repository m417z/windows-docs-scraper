# NVME_CDW11_FEATURE_INTERRUPT_VECTOR_CONFIG structure

## Description

Contains parameters for the Interrupt Vector Configuration Feature that configures settings specific to a particular interrupt vector.

The values from this structure are used in the **InterruptVectorConfig** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.IV`

Indicates the interrupt vector for which the configuration settings are applied.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.CD`

Indicates whether interrupt coalescing settings will be applied for the interrupt vector specified in the **IV** field.

When this value is set to `1`, interrupt coalescing settings will not be applied for the interrupt vector specified in the **IV** field. When this value is cleared to `0`, interrupt coalescing settings will apply for the specified interrupt vector.

By default, coalescing settings are enabled for each interrupt vector. Interrupt coalescing is not supported for the Admin Completion Queue.

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)