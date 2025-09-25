# _SECURE_ELEMENT_CARD_EMULATION_MODE enumeration

## Description

This enumeration indicates the card emulation mode of a secure element.

## Constants

### `EmulationOff`

The secure element is not exposed.

### `EmulationOnPowerIndependent`

The eSE secure element is exposed regardless of the power state of the device/battery and is the only secure element exposed. If the battery is removed, the device is powered off or otherwise power is not available. The secure element must remain exposed to the external reader.

### `EmulationOnPowerDependent`

The secure element is exposed only as long as the device is powered on, and is the only secure element exposed. If the battery is removed, the device is powered off, or if power is not available, the secure element must no longer be exposed to the external reader.

### `EmulationStealthListen`

Indicates that the secure element emulates stealth listening mode.