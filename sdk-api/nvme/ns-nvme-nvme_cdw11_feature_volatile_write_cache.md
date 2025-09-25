# NVME_CDW11_FEATURE_VOLATILE_WRITE_CACHE structure

## Description

Contains parameters for the Volatile Write Cache Feature that controls the volatile write cache, if it is supported and present, on the controller.

> [!NOTE]
> If the controller is able to guarantee that data present in a write cache is written to non-volatile media on loss of power, then that write cache is considered non-volatile and this setting does not apply to that write cache. In that case, this setting has no effect.

The values from this structure are used in the **VolatileWriteCache** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.WCE`

Indicates whether the volatile write cache is enabled.

When this value is set to `1`, the volatile write cache is enabled. When this value is cleared to `0`, the volatile write cache is disabled.

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)