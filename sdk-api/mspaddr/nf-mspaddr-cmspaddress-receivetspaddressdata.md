# CMSPAddress::ReceiveTSPAddressData

## Description

The
**ReceiveTSPAddressData** method is called when a TSP data message is intended to be processed by the address rather than by a specific call. Your MSP must override this method if it wants to handle any per-address TSP messages.

## Parameters

### `pBuffer` [in, out]

Pointer to buffer.

### `dwSize` [out]

Pointer to number of characters in the buffer.