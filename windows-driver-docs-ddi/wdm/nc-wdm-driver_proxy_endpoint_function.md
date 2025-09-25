## Description

The **DRIVER_PROXY_ENDPOINT_FUNCTION** callback defines the function signature for a hot-swappable endpoint function in the DriverProxy system. This is a generic function pointer type that represents any driver function that can be made hot-swappable through the Driver Hot-Swap framework.

## Remarks

Endpoint functions are driver-implemented functions that can be replaced at runtime without unloading the driver. The DriverProxy system creates wrapper functions that redirect calls to the current implementation of each endpoint function, enabling hot-swap functionality.

This callback type serves as a generic function pointer for the DriverProxy system. In practice, endpoint functions will have different signatures depending on their specific purpose, but they are all treated as **DRIVER_PROXY_ENDPOINT_FUNCTION** pointers within the DriverProxy infrastructure.

In Driver Hot-Swap V2, endpoint functions are automatically discovered during the build process through compiler and linker analysis. The compiler identifies functions that should be hot-swappable and places information about them in the `.shsept` section of the binary.

Key characteristics of endpoint functions:

- They can be replaced at runtime through the DriverProxy system
- They are accessed through wrapper functions returned by [**IoGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxywrapperfromendpoint)
- They must be associated with a DriverProxy extension created by [**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)
- Their replacement is coordinated through the DriverProxy infrastructure to ensure thread safety

The actual IRQL requirements for endpoint functions depend on the specific function being implemented. Drivers should design their endpoint functions according to the IRQL constraints of their intended usage.

## See also

[**IoGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxywrapperfromendpoint)

[**IofGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofgetdriverproxywrapperfromendpoint)

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)

[**DRIVER_PROXY_ENDPOINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_endpoint_information)