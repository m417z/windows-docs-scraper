# _CONFIGURABLE_CHARGER_PROPERTY_HEADER structure

## Description

The CONFIGURABLE_CHARGER_PROPERTY_HEADER structure is a header that is used to create your own structure as an input to [IOCTL_INTERNAL_CONFIGURE_CHARGER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/ni-charging-ioctl_internal_configure_charger_property).

## Members

### `Size`

Size of the structure.

### `ChargerId`

The charger ID.

### `PropertyId`

The ID of the property to be configured.

## Remarks

Extend this structure to add your own values for the input to [IOCTL_INTERNAL_CONFIGURE_CHARGER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/ni-charging-ioctl_internal_configure_charger_property). Create a new structure with **CONFIGURABLE_CHARGER_PROPERTY_HEADER** as the first field, and one or more values after it that correspond to your **PropertyId**. Here are two example structures.

```cpp
struct SET_MY_CHARGER_VOLTAGE {
    CONFIGURABLE_CHARGER_PROPERTY_HEADER Header;
    ULONG Voltage;
};
```

```cpp
struct SET_MY_CHARGER_CURRENT_AND_VOLTAGE {
    CONFIGURABLE_CHARGER_PROPERTY_HEADER Header;
    ULONG Current;
    ULONG Voltage;
};
```

Make sure you set **Header.Size** to the appropriate size of your new structure.

```cpp
Header.Size = sizeof(SET_MY_CHARGER_VOLTAGE);
```

## See also

[IOCTL_INTERNAL_CONFIGURE_CHARGER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/ni-charging-ioctl_internal_configure_charger_property)

[**charging.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/)