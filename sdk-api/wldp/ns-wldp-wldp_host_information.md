## Description

A structure identifying the host and source file to be evaluated.

## Members

### `dwRevision`

Must be **WLDP\_HOST\_INFORMATION\_REVISION**.

### `dwHostId`

Enumeration value from [**WLDP\_HOST\_ID**](https://learn.microsoft.com/windows/win32/api/wldp/ne-wldp-wldp_host_id) that describes the host ID.

### `szSource`

Full path and script name with the extension. NULL for **WLDP\_HOST\_ID\_GLOBAL**, or manual script execution.

### `hSource`

In addition to the name, the caller can specify a handle to the file used for validation.

## Remarks

## See also