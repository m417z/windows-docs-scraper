# _CLIENT_DEVICE_INFORMATION structure

## Description

The **CLIENT_DEVICE_INFORMATION** structure is used by the hardware notification callback [HWN_CLIENT_QUERY_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nc-hwnclx-hwn_client_query_device_information) to return the total number of hardware notifications that the client device driver provides.

## Members

### `Version`

Specifies the version number of this structure. This value must be provided by the client driver to the class extension. The class extension is responsible for verifying that this version is supported. The hardware notification payload version number is **HWN_DEVICE_INFORMATION_VERSION**.

### `Size`

The size, in bytes, of the **CLIENT_DEVICE_INFORMATION** data structure.

### `TotalHwNs`

The total number of hardware notifications that the client device driver provides.

## Syntax

```cpp
typedef struct _CLIENT_DEVICE_INFORMATION {
  USHORT  Version;
  USHORT  Size;
  USHORT  TotalHwNs;
} CLIENT_DEVICE_INFORMATION, CLIENT_DEVICE_INFORMATION;
```

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)