# DXGKARG_DPSBMTRANSMISSION structure

## Description

The **DXGKARG_DPSBMTRANSMISSION** structure is a parameter for the [**DXGKDDI_DPSBMTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpsbmtransmission) callback.

## Members

### `CanUseCachedData`

When set, indicates that the driver can return a cached data reply. This data must be in Sideband Message (SBM) packet format.

### `Reserved`

Reserved; do not use.

### `RootPortIndex`

Index value of the DisplayPort-capable connector on which to perform the read or write operation. The driver returned the total number of DP-capable connectors on the GUP in a prior call to [**DXGKDDI_QUERYDPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps). Subsequent calls to [**DXGKDDI_DPSBMTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpsbmtransmission) refer to the DP connectors with **RootPortIndex** ranging from **0** to **NumRootPorts - 1**.

### `BufferSizeSupplied`

Size, in bytes, of the buffer provided in **Data**.

### `RequestLength`

Size in bytes of **Data** in SBM packet size that the driver can directly write into DPCD range for DOWN_REQ.

### `MaxReplyLength`

Maximum size, in bytes, that **Data** is large enough for receiving a reply. The driver needs to discard overflowing packet.

### `DPNativeError`

Field in which the driver can encode more details about the error when returning STATUS_DEVICE_PROTOCOL_ERROR from [**DXGKDDI_DPSBMTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpsbmtransmission).

### `ActualReplyLength`

Length of the actual reply returned by the driver, in bytes.

### `Data`

Buffer containing the data to write for a write operation, or in which to receive the data for a read operation.

## Remarks

## See also

[**DXGKDDI_QUERYDPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps)

[**DXGKDDI_DPSBMTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpsbmtransmission)