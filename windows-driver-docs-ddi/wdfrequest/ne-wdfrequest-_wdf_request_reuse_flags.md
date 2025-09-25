# _WDF_REQUEST_REUSE_FLAGS enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_REUSE_FLAGS** enumeration type defines flags that are used in a driver's [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure.

## Constants

### `WDF_REQUEST_REUSE_NO_FLAGS:0x00000000`

No flags are set.

### `WDF_REQUEST_REUSE_SET_NEW_IRP:0x00000001`

The **NewIrp** member of the [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure is valid.

## See also

[WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params)