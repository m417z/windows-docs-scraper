# UART_INITIALIZE_PORT callback function

## Description

Initializes or resets the UART hardware. This callback function is called before calling any other driver functions.

## Parameters

### `LoadOptions`

 [_In_opt_Optional _Null_terminated_] A null-terminated load option string.

### `Port` [_Inout_]

A pointer to a [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure that is filled with information about port initialization.

### `MemoryMapped`

A boolean value that indicates whether the UART hardware is accessed through memory-mapped registers or legacy port I/O.

### `AccessSize`

An ACPI Generic Access Size value that indicates the type of bus access that should be performed when accessing the UART hardware.

### `BitWidth`

A number that indicates the width of the UART registers.

## Return value

Returns TRUE if the port has been successfully initialized, FALSE otherwise.

## Prototype

```cpp
//Declaration

UART_INITIALIZE_PORT UartInitializePort;

// Definition

BOOLEAN UartInitializePort
(
	PCHAR LoadOptions
	PCPPORT Port
	BOOLEAN MemoryMapped
	UCHAR AccessSize
	UCHAR BitWidth
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver).

## See also

[**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver)

[**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport)

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)