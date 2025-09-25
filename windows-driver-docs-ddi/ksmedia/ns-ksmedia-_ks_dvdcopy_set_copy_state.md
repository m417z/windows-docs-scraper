# _KS_DVDCOPY_SET_COPY_STATE structure

## Description

The KS_DVDCOPY_SET_COPY_STATE structure is used to specify the copyright protection state of the DVD decoder stream.

## Members

### `DVDCopyState`

Indicates the progress of the copyright protection initialization, authentication and key negotiation sequence. This must be one of the values from the [KS_DVDCOPYSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_dvdcopystate) enumeration.

## Remarks

This structure is used by the [KSPROPERTY_DVDCOPY_SET_COPY_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-set-copy-state) property.

For more information, see [DVD Copyright Protection](https://learn.microsoft.com/windows-hardware/drivers/stream/dvd-copyright-protection), [Multiple Data Streams on the same Hardware](https://learn.microsoft.com/windows-hardware/drivers/stream/multiple-data-streams-on-the-same-hardware) and [Synchronizing Key Exchange with Data Flow](https://learn.microsoft.com/windows-hardware/drivers/stream/synchronizing-key-exchange-with-data-flow).

## See also

[KSPROPERTY_DVDCOPY_SET_COPY_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-set-copy-state)

[KS_DVDCOPYSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_dvdcopystate)