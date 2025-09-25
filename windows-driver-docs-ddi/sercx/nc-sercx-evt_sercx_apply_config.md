# EVT_SERCX_APPLY_CONFIG callback function

## Description

The *EvtSerCxApplyConfig* event callback function instructs the serial controller driver to apply a list of configuration settings to the serial controller hardware.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `ConnectionParameters` [in]

A pointer to the connection parameters structure. This function must cast this parameter to the appropriate pointer type, parse the data structure to obtain the configuration settings, and apply these settings to the serial controller hardware. The connection parameters structure is defined by the hardware platform vendor and is opaque to both the serial framework extension (SerCx) and the operating system.

## Return value

The *EvtSerCxApplyConfig* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

SerCx calls this function during initialization of the serial controller to ensure that the hardware is in a valid initial state. Additionally, this function is called whenever a client sends an [IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_apply_default_configuration) I/O control request to the controller.

SerCx obtains these configuration parameters from the ACPI resource descriptor for the serial controller device. The data format that the ACPI firmware uses to store these configuration settings should be the same data format that is expected by the serial controller driver.

When a client sends an **IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION** request to a serial port that is managed by SerCx, SerCx determines whether the serial controller driver for the serial port supports the *EvtSerCxApplyConfig* callback, and whether the ACPI resource descriptor for the serial port provides default connection settings. If not, SerCx completes the request with error status code STATUS_NOT_SUPPORTED. Otherwise, SerCx passes the connection parameters to the driver's *EvtSerCxApplyConfig* callback function. After this callback returns, SerCx completes the request and uses the return value from the callback as the status code for the request.

If a serial controller driver needs to obtain the default connection parameters at a time other than during an *EvtSerCxApplyConfig* callback, the driver can call the [SerCxGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetconnectionparameters) method.

To register an *EvtSerCxApplyConfig* callback function, the driver must call the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method.

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef NTSTATUS
  EVT_SERCX_APPLY_CONFIG(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxApplyConfig* callback function that is named `MyEvtSerCxApplyConfig`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_APPLY_CONFIG MyEvtSerCxApplyConfig;
```

Then, implement your callback function as follows.

```cpp
NTSTATUS
  MyEvtSerCxApplyConfig(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

The following code example shows a partial implementation of an *EvtSerCxApplyConfig* function for a UART.

```cpp
//
// Define the UART ACPI descriptor, plus any vendor-specific
// data that is needed by the serial controller (UART) driver.
//

#define ANYSIZE_ARRAY 1

//
// Common resource name descriptor
//
typedef struct _PNP_IO_DESCRIPTOR_RESOURCE_NAME {
    UCHAR ResourceIndex;
    UCHAR ResourceName[ANYSIZE_ARRAY];
} PNP_IO_DESCRIPTOR_RESOURCE_NAME, *PPNP_IO_DESCRIPTOR_RESOURCE_NAME;

//
// Bus descriptor for a UART
//
typedef struct _PNP_UART_SERIAL_BUS_DESCRIPTOR {
    PNP_SERIAL_BUS_DESCRIPTOR SerialBusDescriptor;
    ULONG BaudRate;
    USHORT RxBufferSize;
    USHORT TxBufferSize;
    UCHAR Parity;
    // Include any optional vendor data here:
    ...
    // Append the PNP_IO_DESCRIPTOR_RESOURCE_NAME here:
    ....
} PNP_UART_SERIAL_BUS_DESCRIPTOR, *PPNP_UART_SERIAL_BUS_DESCRIPTOR;

EVT_SERCX_APPLY_CONFIG UartEvtApplyConfig;

//
// Implementation of an EvtSerCxApplyConfig callback function
//
NTSTATUS
  UartEvtApplyConfig(
    __in WDFDEVICE Device,
    __in PVOID ConnectionParameters
    )
{
    NTSTATUS status = STATUS_SUCCESS;
    PRH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER connection;
    PPNP_SERIAL_BUS_DESCRIPTOR descriptor;
    PPNP_UART_SERIAL_BUS_DESCRIPTOR uartDescriptor;

    if (ConnectionParameters == NULL)
    {
        status = STATUS_INVALID_PARAMETER;
    }

    if (NT_SUCCESS(status))
    {
        connection = (PRH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER)ConnectionParameters;

        if (connection->PropertiesLength < sizeof(PNP_SERIAL_BUS_DESCRIPTOR))
        {
            status = STATUS_INVALID_PARAMETER;
        }
    }

    if (NT_SUCCESS(status))
    {
        descriptor = (PPNP_SERIAL_BUS_DESCRIPTOR)connection->ConnectionProperties;

        if (descriptor->SerialBusType != UART_SERIAL_BUS_TYPE)
        {
            status = STATUS_INVALID_PARAMETER;
        }
    }

    if (NT_SUCCESS(status))
    {
        uartDescriptor = (PPNP_UART_SERIAL_BUS_DESCRIPTOR)connection->ConnectionProperties;

        // Apply the configuration settings from
        // the UART descriptor.
        ...
    }

    return status;
}
```

The PRH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER and PPNP_SERIAL_BUS_DESCRIPTOR pointer types in the preceding code example are defined in the Reshub.h header file.

## See also

[IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_apply_default_configuration)

[SerCxGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetconnectionparameters)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)