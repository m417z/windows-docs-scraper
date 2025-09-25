# PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY structure

## Description

Contains process mitigation policy settings for Control Flow Guard (CFG). The [GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy) and [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy) functions use this structure.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

This member is reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableControlFlowGuard`

CFG is enabled for the process if this flag is set. This field cannot be changed via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableExportSuppression`

If TRUE, exported functions will be treated as invalid indirect call targets by default. Exported functions only become valid indirect call targets if they are dynamically resolved via [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). This field cannot be changed via [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.StrictMode`

If TRUE, all DLLs that are loaded must enable CFG. If a DLL does not enable CFG then the image will fail to load. This policy can be enabled after a process has started by calling [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy). It cannot be disabled once enabled.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

This member is reserved for system use.