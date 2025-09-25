# _DOT11_WFD_DEVICE_TYPE structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_DEVICE_TYPE** structure is used to specify primary and secondary device types.

## Members

### `CategoryID`

The identifier of the main type category.

### `SubCategoryID`

The identifier of the type subcategory.

### `OUI`

The Organizationally Unique Identifier (OUI) assigned to a device.

## Syntax

```cpp
typedef struct _DOT11_WFD_DEVICE_TYPE {
  USHORT   CategoryID;
  USHORT   SubCategoryID;
  UCHAR    OUI[4];
} DOT11_WFD_DEVICE_TYPE, *PDOT11_WFD_DEVICE_TYPE;
```

## Remarks

The **DOT11_WFD_DEVICE_TYPE** data is provided in host byte-ordering. The miniport may need to convert the data to an ordering appropriate for inclusion in Peer-to-Peer Information Elements.