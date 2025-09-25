# _NDIS_MINIPORT_PAUSE_PARAMETERS structure

## Description

The NDIS_MINIPORT_PAUSE_PARAMETERS structure defines pause parameters for miniport adapters.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_PAUSE_PARAMETERS structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_MINIPORT_PAUSE_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MINIPORT_PAUSE_PARAMETERS_REVISION_1.

### `Flags`

Reserved.

### `PauseReason`

The value of this member depends on the NDIS version a miniport driver is targeting.

| Miniport driver NDIS version | Value |
| --- | --- | --- |
| Earlier than NDIS 6.40 | Unpredictable values. Miniport drivers should not rely on the value of this member. |
| 6.40 and later | NDIS_PAUSE_MINIPORT_DEVICE_REMOVE under specific conditions, otherwise NDIS_PAUSE_NDIS_INTERNAL. |

For NDIS 6.40 and later miniport drivers running on Windows 10, version 1903 and later, the value of this member might be NDIS_PAUSE_MINIPORT_DEVICE_REMOVE if NDIS guarantees that the miniport adapter instance will never receive a [*MiniportRestart*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) call again. Otherwise, this value is NDIS_PAUSE_NDIS_INTERNAL. If the NDIS_PAUSE_MINIPORT_DEVICE_REMOVE flag is set, miniport drivers can optionally make aggressive performance optimizations in their [*MiniportPause*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) handler that assume that the adapter's datapath will never be restarted. NDIS 6.40 and later drivers will never see NDIS_PAUSE_MINIPORT_DEVICE_REMOVE on versions of Windows earlier than Windows 10, version 1903.

## Remarks

To define miniport adapter pause parameters, NDIS passes a pointer to an
NDIS_MINIPORT_PAUSE_PARAMETERS structure to the
[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) function.

## See also

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)