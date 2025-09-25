# _DOT11_MAC_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_MAC_PARAMETERS** is the optional input for an [OID_DOT11_CREATE_MAC](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-create-mac) request. The device role is defined in an operation mode bitmask included in this structure.

## Members

### `Header`

The object header identifying the type and revision of this structure. The required member settings of [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) are the following:

#### Type

Must be set to **NDIS_OBJECT_TYPE_DEFAULT**

#### Revision

Must be set to **DOT11_MAC_PARAMETERS_REVISION_1**

#### Size

Must be set to **DOT11_SIZEOF_MAC_PARAMETERS_REVISION_1**

### `uOpmodeMask`

A bitwise OR value of the operation modes Windows may set for the created port. This bitmask is defined through the following:

#### DOT11_OPERATION_MODE_WFD_DEVICE

Specifies that the miniport driver supports the Wi-Fi Direct Device operation mode.

#### DOT11_OPERATION_MODE_WFD_GROUP_OWNER

Specifies that the miniport driver supports the Wi-Fi Direct Group Owner operation mode.

#### DOT11_OPERATION_MODE_WFD_CLIENT

Specifies that the miniport driver supports the Wi-Fi Direct Client operation mode.

## Syntax

```cpp
typedef struct _DOT11_MAC_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  ULONG              uOpmodeMask;
} DOT11_MAC_PARAMETERS, *PDOT11_MAC_PARAMETERS;
```

## See also

[OID_DOT11_CREATE_MAC](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-create-mac)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)