# WTS_PROTOCOL_COUNTERS structure

## Description

Contains protocol performance counters.

## Members

### `WdBytes`

The number of bytes sent and received.

### `WdFrames`

The number of frames sent and received.

### `WaitForOutBuf`

The number of times the protocol waited for an output buffer to become available.

### `Frames`

Transport driver number of frames sent and received.

### `Bytes`

Transport driver number of bytes sent and received.

### `CompressedBytes`

The number of compressed bytes.

### `CompressFlushes`

The number of compressed flushes. A compressed flush occurs when compression for a packet fails and is replaced by the original uncompressed packet.

### `Errors`

The number of packets that were in error during the session.

### `Timeouts`

The number of timeouts during the session.

### `AsyncFramingError`

The number of asynchronous framing errors during the session.

### `AsyncOverrunError`

The number of asynchronous overrun errors during the session.

### `AsyncOverflowError`

The number of asynchronous overflow errors during the session.

### `AsyncParityError`

The number of asynchronous parity errors during the session.

### `TdErrors`

The number of transport protocol errors during the session.

### `ProtocolType`

The type of the protocol.

### `Length`

The length of data in the **Reserved** field.

### `Specific`

Specifies the type of counter that can be queried. This can be **TShareCounters** or **Reserved**.

### `Reserved`

An array of protocol specific data. The maximum length can be WTS_MAX_RESERVED multiplied by the size of an unsigned long integer.

## Remarks

This structure is used by the [WTS_PROTOCOL_STATUS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_protocol_status) structure.