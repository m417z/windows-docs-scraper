## Description

The query is passed a **KSRATE** structure appended to the property containing the rate request (known as a [**KSRATE_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksrate_capability) structure), and is returned a **KSRATE** structure filled in with the capability given the rate request.

## Members

### `PresentationStart`

Specifies the start point for the rate in presentation time units.

### `Duration`

Specifies the duration of the rate in presentation time units.

### `Interface`

A structure of type [**KSPIN_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure) that specifies either the interface used in the connection this rate request is being sent to, or the interface of a related connection. This allows the time units to be interpreted by the pin.

### `Rate`

Specifies the rate in terms of 1/10th percentage points, where 1000 is the nominal 1.0 rate, 500 is 0.5 rate, and so on. Negative numbers indicate reverse rates.

### `Flags`

Possible flag values are listed in the following table.

| Flag | Description |
|---|---|
| KSRATE_NOPRESENTATIONSTART | Specifies that there is no valid start time in this rate change request or query. |
| KSRATE_NOPRESENTATIONDURATION | Specifies that there is no valid duration in this rate change request or query. |

## See also

[KSRATE_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksrate_capability)