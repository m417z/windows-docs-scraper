## Description

Specifies result values for execution authorization queries with [WldpCanExecuteBuffer](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpcanexecutebuffer), [WldpCanExecuteFile](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpcanexecutefile), and [WldpCanExecuteStream](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpcanexecutestream).

## Constants

### `WLDP_EXECUTION_POLICY_BLOCKED`

The subject does not pass execution policy and should not be executed.

### `WLDP_EXECUTION_POLICY_ALLOWED`

The subject passes execution policy and should be executed normally

### `WLDP_EXECUTION_POLICY_REQUIRE_SANDBOX`

While the subject does not pass execution policy, the execution policy allows for execution in a sandbox-like mode if one is available for the host. If a sandbox mode is available for the host, the script may be executed in that mode. Otherwise, the execution of the subject should be aborted.

## Remarks

## See also