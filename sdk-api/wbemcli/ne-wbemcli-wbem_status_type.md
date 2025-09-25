# WBEM_STATUS_TYPE enumeration

## Description

Describes the status of an asynchronous operation.

## Constants

### `WBEM_STATUS_COMPLETE:0`

The operation has completed.

### `WBEM_STATUS_REQUIREMENTS:1`

Used in activating post-filtering.

### `WBEM_STATUS_PROGRESS:2`

The operation is still in progress.

### `WBEM_STATUS_LOGGING_INFORMATION:0x100`

Reserved for future use.

### `WBEM_STATUS_LOGGING_INFORMATION_PROVIDER:0x200`

Reserved for future use.

### `WBEM_STATUS_LOGGING_INFORMATION_HOST:0x400`

Reserved for future use.

### `WBEM_STATUS_LOGGING_INFORMATION_REPOSITORY:0x800`

Reserved for future use.

### `WBEM_STATUS_LOGGING_INFORMATION_ESS:0x1000`

Reserved for future use.

## See also

[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus)

[IWbemServices::ExecQueryAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execqueryasync)