# _CLIENT_CONTROLLER_BASIC_INFORMATION structure

## Description

The **CLIENT_CONTROLLER_BASIC_INFORMATION** structure contains general-purpose I/O (GPIO) controller hardware attributes and configuration information.

## Members

### `Version`

The version number of this structure. Set this member to **GPIO_CONTROLLER_BASIC_INFORMATION_VERSION**, which is defined in the Gpioclx.h header file.

### `Size`

The size, in bytes, of this structure. Set this member to **sizeof**(**CLIENT_CONTROLLER_BASIC_INFORMATION**).

### `TotalPins`

The number of pins on the GPIO controller. If the pins are partitioned into multiple banks, this member specifies the total pin count across all of the banks in the GPIO controller.

### `NumberOfPinsPerBank`

The number of GPIO pins for each bank. The maximum number of pins for each bank is 64. The pins on the GPIO controller are partitioned into one or more banks. Each bank contains the number of pins specified by this parameter, with the possible exception of the last bank. For more information, see Remarks.

### `DeviceIdleTimeout`

The idle time-out interval, in milliseconds, if the GPIO controller supports the D3 power state. The time-out interval is the minimum amount of time that a GPIO controller stays in the D0 state after the controller becomes idle. After the time-out interval expires, the power manager might request that the controller switch to the D3 state.

### `Flags`

A set of flags that specify the hardware attributes of the GPIO controller. This member can be set to all zeros or to any bitwise-OR combination of the following flag bits:

* **MemoryMappedController**
* **ActiveInterruptsAutoClearOnRead**
* **FormatIoRequestsAsMasks**
* **DeviceIdlePowerMgmtSupported**
* **BankIdlePowerMgmtSupported**
* **EmulateDebouncing**
* **EmulateActiveBoth**

For more information, see [CONTROLLER_ATTRIBUTE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_controller_attribute_flags).

## Remarks

The [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function uses a **CLIENT_CONTROLLER_BASIC_INFORMATION** structure to pass device-specific information about a GPIO controller to the GPIO framework extension (GpioClx).

A GPIO controller driver can partition the pins in a GPIO controller device into some number of banks. If N is the number of banks in the controller, the banks are numbered 0 to N–1. All except the last bank (that is, bank number N–1) must contain the number of pins specified in the **NumberOfPinsPerBank** member. The last bank can have any number of pins from one to **NumberOfPinsPerBank**.

GpioClx determines the total number of banks in the GPIO controller from the values of the **TotalPins** and **NumberOfPinsPerBank** members. GpioClx uses the following integer formula to calculate the total number of banks:

**TotalPins**
**NumberOfPinsPerBank**
**NumberOfPinsPerBank**
Typically, a bank in a GPIO controller device can be turned on and off independently of the other banks in the same device. Thus, power can be saved by turning off a bank that is idle.

## See also

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CONTROLLER_ATTRIBUTE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_controller_attribute_flags)