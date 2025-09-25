# DOT11_ROAMING_COMPLETION_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_ROAMING_COMPLETION_PARAMETERS structure specifies the completion results of the roaming
operation performed by the Native 802.11 miniport driver. The driver includes a
DOT11_ROAMING_COMPLETION_PARAMETERS structure when the driver makes an
[NDIS_STATUS_DOT11_ROAMING_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-roaming-completion) status indication.

## Members

### `Header`

The type, revision, and size of the DOT11_ROAMING_COMPLETION_PARAMETERS structure. This member is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
*Header* to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_ROAMING_COMPLETION_PARAMETERS_REVISION_1.

#### Size

This member must be set to
`sizeof(DOT11_ROAMING_COMPLETION_PARAMETERS)`.

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The completion status of the roaming operation formatted as a
[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes) value.

## Syntax

```cpp
typedef struct DOT11_ROAMING_COMPLETION_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_ASSOC_STATUS uStatus;
} DOT11_ROAMING_COMPLETION_PARAMETERS, *PDOT11_ROAMING_COMPLETION_PARAMETERS;
```

## Remarks

For more information about the roaming operation, see
[Roaming Operations](https://learn.microsoft.com/windows-hardware/drivers/network/roaming-operations).

## See also

[NDIS_STATUS_DOT11_ROAMING_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-roaming-completion)

[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes)