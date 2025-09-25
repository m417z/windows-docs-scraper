# _CMP_MONITOR_PLUGS structure

## Description

This structure is used to monitor plug access. The request allows a driver to monitor all access to local oPCR and iPCR plugs.

## Members

### `Flags`

On input, the caller sets this member to REGISTER_MONITOR_PLUG_NOTIFY to register to monitor all local plug access. This member can also be set to DEREGISTER_MONITOR_PLUG_NOTIFY to stop monitoring local plug access.

### `pfnNotify`

On input, a pointer to a caller-supplied function to be called by the protocol driver when a local plug is accessed.

This function uses the following prototype:

```
typedef void
(*PCMP_MONITOR_ROUTINE) (
  IN PCMP_MONITOR_INFO  MonitorInfo
  );
```

#### MonitorInfo

On input, a pointer to a [CMP_MONITOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cmp_monitor_info) structure containing the contents of the plug that was modified.

### `Context`

On input, a pointer to a caller-defined context for the function at **pfnNotify**.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)