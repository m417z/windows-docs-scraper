# MFCARD_DES structure

## Description

The MFCARD_DES structure is used for specifying either a resource list or a resource requirements list that describes resource usage by *one* of the hardware functions provided by an instance of a multifunction device. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `PMF_Count`

Must be 1.

### `PMF_Type`

*Not used.*

### `PMF_Flags`

One bit flag is defined, as described in the following table.

| Flag | Definition |
| --- | --- |
| fPMF_AUDIO_ENABLE | If set, audio is enabled. |

### `PMF_ConfigOptions`

Contents of the 8-bit PCMCIA Configuration Option Register.

### `PMF_IoResourceIndex`

Zero-based index indicating the [IO_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_resource) structure that describes the I/O resources for the hardware function being described by this MFCARD_DES structure.

### `PMF_Reserved`

*Not used.*

### `PMF_ConfigRegisterBase`

Offset from the beginning of the card's attribute memory space to the base configuration register address.

## See also

[IO_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_resource)