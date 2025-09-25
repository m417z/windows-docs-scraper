# MBN_PIN_TYPE enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_PIN_TYPE** enumerated type indicates the type of password required for unlocking the information stored on the interface.

## Constants

### `MBN_PIN_TYPE_NONE:0`

Indicates that no PIN is pending to be entered.

### `MBN_PIN_TYPE_CUSTOM`

Indicates a custom PIN code.

### `MBN_PIN_TYPE_PIN1`

Indicates a PIN1 code. For CDMA devices, PIN1 represents the power-on device lock code. For GSM devices, PIN1 represents the SIM lock, also referred to as PIN in GSM terminology.

### `MBN_PIN_TYPE_PIN2`

Indicates a PIN2 code.

### `MBN_PIN_TYPE_DEVICE_SIM_PIN`

Indicates a device to SIM password.

### `MBN_PIN_TYPE_DEVICE_FIRST_SIM_PIN`

Indicates a device to very first SIM password.

### `MBN_PIN_TYPE_NETWORK_PIN`

Indicates a network personalization password.

### `MBN_PIN_TYPE_NETWORK_SUBSET_PIN`

Indicates a network subset personalization password.

### `MBN_PIN_TYPE_SVC_PROVIDER_PIN`

Indicates a Service Provider (SP) personalization password.

### `MBN_PIN_TYPE_CORPORATE_PIN`

Indicates a corporate personalization password.

### `MBN_PIN_TYPE_SUBSIDY_LOCK`

Indicates a subsidy unlock code.