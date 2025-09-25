## Description

The **DRIVER_PROXY_REGISTER_CALLBACK_PHASE** enumeration defines the different phases during which a [**DRIVER_PROXY_REGISTER_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_register_callback) callback can be invoked during endpoint registration or hot-swap operations.

## Constants

### `DriverProxyRegisterCallbackPreProcess`

Indicates the pre-processing phase. The callback is invoked before any endpoint function switching begins, allowing the driver to perform preparation operations such as acquiring locks, saving state, or notifying other components of the impending change.

### `DriverProxyRegisterCallbackProxyStalled`

Indicates the proxy stalled phase. The callback is invoked while all calls to registered endpoints are blocked (stalled). During this phase, the DriverProxy system has acquired the rundown lock and no new calls to endpoint functions will proceed. This is the safest time for the driver to perform operations that require exclusive access to resources that might be accessed by endpoint functions.

### `DriverProxyRegisterCallbackPostProcess`

Indicates the post-processing phase. The callback is invoked after endpoint function switching is complete and normal operation has resumed. This allows the driver to perform cleanup operations, release locks, update state, or notify other components that the hot-swap operation has completed.

### `DriverProxyRegisterCallbackMax`

Maximum value for the enumeration. This value is not used as a callback phase and is reserved for internal validation purposes.

## Remarks

This enumeration is used by [**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints) to indicate which phase of the registration process is currently executing when the [**DRIVER_PROXY_REGISTER_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_register_callback) callback is invoked.

The callback phases occur in a specific sequence during endpoint registration or hot-swap operations:

1. **DriverProxyRegisterCallbackPreProcess**: Called before any function switching begins.
2. **DriverProxyRegisterCallbackProxyStalled**: Called while all endpoint calls are blocked.
3. **DriverProxyRegisterCallbackPostProcess**: Called after function switching is complete.

Each phase serves a different purpose in the hot-swap operation:

- The **PreProcess** phase allows drivers to prepare for the upcoming change.
- The **ProxyStalled** phase provides exclusive access when endpoint calls are blocked.
- The **PostProcess** phase allows drivers to clean up after the change is complete.

The callback must return **STATUS_SUCCESS** for the operation to continue. If any callback phase returns a failure status, the entire registration operation will fail and any partial changes will be rolled back.

## See also

[**DRIVER_PROXY_REGISTER_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_register_callback)

[**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints)

[**DRIVER_PROXY_ENDPOINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_endpoint_information)