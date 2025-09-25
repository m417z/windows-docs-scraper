## Description

The **DRIVER_PROXY_REGISTER_CALLBACK** callback defines a routine that is invoked at different phases during DriverProxy endpoint registration and hot-swap operations.

## Parameters

### `Phase`

[in] A [**DRIVER_PROXY_REGISTER_CALLBACK_PHASE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-driver_proxy_register_callback_phase) value that indicates which phase of the registration process is currently executing.

### `Context`

[in, optional] A pointer to driver-defined context information that was passed to [**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints). This parameter can be NULL if no context was provided.

## Return value

**DRIVER_PROXY_REGISTER_CALLBACK** returns one of the following NTSTATUS values:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The callback completed successfully. The endpoint registration process will continue to the next phase. |
| **Other NTSTATUS values** | The callback encountered an error. The entire endpoint registration operation will fail and any partial changes will be rolled back. |

## Remarks

This callback allows drivers to perform custom operations at specific points during the endpoint registration process, enabling coordination with the hot-swap mechanism.

This callback is invoked by [**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints) during endpoint registration and hot-swap operations. The callback runs at PASSIVE_LEVEL and provides drivers with the opportunity to coordinate with the DriverProxy system during critical phases of the hot-swap process.

The callback is invoked in a specific sequence during endpoint registration:

1. **Pre-processing phase**: Called before any endpoint function switching begins. Drivers can use this phase to prepare for the upcoming change, such as:
   - Acquiring driver-specific locks
   - Saving current state
   - Notifying other driver components
   - Preparing resources needed during the switch

2. **Proxy stalled phase**: Called while all calls to registered endpoints are blocked. During this phase, the DriverProxy system holds the rundown lock and no new calls to endpoint functions will proceed. This is the safest time to perform operations that require exclusive access to resources that might be accessed by endpoint functions, such as:
   - Updating shared data structures
   - Reconfiguring hardware
   - Modifying global driver state

3. **Post-processing phase**: Called after endpoint function switching is complete and normal operation has resumed. Drivers can use this phase for cleanup operations, such as:
   - Releasing driver-specific locks
   - Updating internal state
   - Notifying other components of completion
   - Logging or performance tracking

The callback must return **STATUS_SUCCESS** for the registration to continue. Any failure will cause the entire operation to fail and roll back.

During the **DriverProxyRegisterCallbackProxyStalled** phase, all endpoint calls are blocked, so the callback should perform operations quickly to minimize system disruption.

The callback should not perform operations that might call back into the same DriverProxy extension, as this could cause deadlocks.

The callback is optional and can be NULL if no driver-specific coordination is needed during endpoint registration.

## See also

[**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints)

[**DRIVER_PROXY_REGISTER_CALLBACK_PHASE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-driver_proxy_register_callback_phase)

[**DRIVER_PROXY_ENDPOINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_endpoint_information)

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)