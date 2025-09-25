# EVT_SERCX2_APPLY_CONFIG callback function

## Description

The *EvtSerCx2ApplyConfig* event callback function is called by version 2 of the serial framework extension (SerCx2) to supply the serial controller driver with a list of device-specific configuration settings to apply to the serial controller hardware.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `ConnectionParameters` [in]

A pointer to the connection parameters structure. This function must cast the pointer to the appropriate pointer type, parse the data structure to obtain the configuration settings, and apply these settings to the serial controller hardware. The connection parameters structure is defined by the hardware platform vendor and is opaque to both SerCx2 and the operating system. For more information, see Remarks.

## Return value

The *EvtSerCx2ApplyConfig* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

Your serial controller driver must implement this function. The driver registers the function in the call to the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method that finishes the initialization of the framework device object for the serial controller.

SerCx2 calls the *EvtSerCx2ApplyConfig* function during initialization of the serial controller to ensure that the hardware is in a valid initial state. Additionally, this function is called whenever a client sends an [IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_apply_default_configuration) request to the serial controller.

SerCx2 obtains the configuration parameters from the vendor-defined data field in the ACPI resource descriptor for the serial controller device. The data format that the ACPI firmware uses to store these configuration settings should be the same data format that is expected by the serial controller driver. For more information, see the description of the *UART serial bus connection descriptor* in the [ACPI 5.0 specification](https://uefi.org/specifications).

When a client sends an **IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION** request to a serial port that is managed by SerCx2, SerCx2 calls the *EvtSerCx2ApplyConfig* function to pass the configuration parameters to the serial controller driver. After this callback returns, SerCx2 completes the request and uses the return value from the callback as the status code for the request.

#### Examples

To define an *EvtSerCx2ApplyConfig* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2ApplyConfig* callback function that is named `MyApplyConfig`, use the **EVT_SERCX2_APPLY_CONFIG** function type, as shown in this code example:

```cpp
EVT_SERCX2_APPLY_CONFIG  MyApplyConfig;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyApplyConfig(
    WDFDEVICE  Device,
    PVOID  ConnectionParameters
    )
  {...}
```

The **EVT_SERCX2_APPLY_CONFIG** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_APPLY_CONFIG** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

The following code example shows a partial implementation of an *EvtSerCx2ApplyConfig* function for a UART:

```cpp
//
// Define the UART ACPI descriptor, plus any vendor-specific
// data that is needed by the serial controller (UART) driver.
//

#define ANYSIZE_ARRAY 1
#include <pshpack1.h>

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

#include <poppack.h>

EVT_SERCX_APPLY_CONFIG MyApplyConfig;

//
// Implementation of an EvtSerCx2ApplyConfig callback function
//
_Use_decl_annotations_
VOID
  MyApplyConfig(
    WDFDEVICE Device,
    PVOID ConnectionParameters
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

        // Apply the platform-specific configuration settings
        // from the UART descriptor here:
        ...
    }

    return status;
}
```

The pshpack1.h and poppack.h header files in the preceding code example control the structure alignment mode used by the compiler. The PRH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER and PPNP_SERIAL_BUS_DESCRIPTOR pointer types are pointers to [RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/reshub/ns-reshub-_rh_query_connection_properties_output_buffer) and [PNP_SERIAL_BUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/reshub/ns-reshub-_pnp_serial_bus_descriptor) structures. For more information about the members of the **PNP_UART_SERIAL_BUS_DESCRIPTOR** structure, see Table 6-193 in the [ACPI 5.0 specification](https://uefi.org/specifications).

## See also

[IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_apply_default_configuration)

[PNP_SERIAL_BUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/reshub/ns-reshub-_pnp_serial_bus_descriptor)

[RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/reshub/ns-reshub-_rh_query_connection_properties_output_buffer)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)