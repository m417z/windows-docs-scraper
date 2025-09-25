# _GPIO_PIN_IORESTRICTION_TYPE enumeration (pepfx.h)

## Description

The **GPIO_PIN_IORESTRICTION_TYPE** enumeration describes the functions that a GPIO pin is limited to performing.

## Constants

### `IoRestrictionNone`

Indicates that the GPIO pin is not restricted to either input or output. When no IO restriction is described, it is assumed to be **IoRestrictionNone**.

### `IoRestrictionInputOnly`

Indicates that the GPIO pin is restricted to input.

### `IoRestrictionOutputOnly`

Indicates that the GPIO pin is restricted to output.

### `IoRestrictionNoneAndPreserve`

Indicates that the GPIO pin is not restricted to either input or output and that the mode should be preserved when the driver is unloaded.