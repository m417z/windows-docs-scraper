# MIRACAST_PROTOCOL_EVENT enumeration

## Description

Specifies the types of wireless display (Miracast) protocol event that the user-mode display driver should report.

## Constants

### `MIRACAST_PROTOCOL_EVENT_IFRAME_RQ`

The driver received a request for a new IDR type of I-frame from the Miracast sink.

### `MIRACAST_PROTOCOL_EVENT_MONITOR_ARRIVE`

The driver received a monitor connection event from the Miracast sink.

### `MIRACAST_PROTOCOL_EVENT_MONITOR_DEPART`

The driver received a monitor disconnection event from the Miracast sink.

### `MIRACAST_PROTOCOL_EVENT_SINK_FAILED_PREFERRED_MODE_CHANGE`

Reserved for system use. Do not use in your driver.

### `MIRACAST_PROTOCOL_EVENT_FORCE_UINT32`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.