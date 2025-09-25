## Description

The **PCC_REDUCED_2_SUBSPACE** structure contains information about the ACPI Platform Communication Channel (PCC) HW-reduced Type 2 subspace.

## Members

### `Header`

The **PCC_SUBSPACE_HEADER** header.

### `PlatformInterruptGsiv`

The PCC platform global system interrupt vector (GSIV).

### `PlatformInterruptPolarity`

The PCC platform interrupt polarity value (one of **PCC_PLATFORM_INTERRUPT_POLARITY_XXX**).

### `PlatformInterruptMode`

The PCC platform interrupt mode (must be **PCC_PLATFORM_INTERRUPT_MODE_EDGE_TRIGGERED**).

### `Reserved1`

Reserved for future use.

### `PlatformInterruptFlags`

The PCC platform interrupt flags.

### `Reserved2`

Reserved for future use.

### `BaseAddress`

The **PHYSICAL_ADDRESS** base address.

### `Length`

The length value.

### `DoorbellRegister`

The **GEN_ADDR** doorbell register.

### `DoorbellPreserve`

The doorbell preserve mask.

### `DoorbellWrite`

The doorbell write mask.

### `NominalLatency`

The nominal latency value.

### `MaximumPeriodicAccessRate`

The maximum periodic access rate value.

### `MinimumRequestTurnaroundTime`

The minimum request turnaround time value.

### `PlatformInterruptAckRegister`

The **GEN_ADDR** platform interrupt ack register.

### `PlatformInterruptAckPreserve`

The platform interrupt ack preserve mask.

### `PlatformInterruptAckWrite`

The platform interrupt ack write mask.

## Remarks

## See also