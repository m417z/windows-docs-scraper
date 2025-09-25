# _KS_DVDCOPY_BUSKEY structure

## Description

The KS_DVDCOPY_BUSKEY structure is used to describe the bus key information for the DVD copyright protection authentication process.

## Members

### `BusKey`

Specifies the DVD decoder minidriver's bus key.

### `Reserved`

Reserved. Do not use.

## Remarks

The KS_DVDCOPY_BUSKEY structure is used by both the [KSPROPERTY_DVDCOPY_DVD_KEY1](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-dvd-key1) and [KSPROPERTY_DVDCOPY_DEC_KEY2](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-dec-key2) properties.

For more information, see [DVD Copyright Protection](https://learn.microsoft.com/windows-hardware/drivers/stream/dvd-copyright-protection).

## See also

[KSPROPERTY_DVDCOPY_DEC_KEY2](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-dec-key2)

[KSPROPERTY_DVDCOPY_DVD_KEY1](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-dvd-key1)