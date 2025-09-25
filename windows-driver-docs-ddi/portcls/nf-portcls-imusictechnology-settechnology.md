# IMusicTechnology::SetTechnology

## Description

The `SetTechnology` method changes the **Technology** member of each [KSDATARANGE_MUSIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdatarange_music) structure in the data ranges for the miniport driver's pins.

## Parameters

### `Technology` [in]

Specifies a technology GUID. This parameter should point to one of the GUIDs that are defined for the **Technology** member of the [KSDATARANGE_MUSIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdatarange_music) structure.

## Return value

`SetTechnology` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `SetTechology` method should be called before the miniport driver's **Init** method. If `SetTechnology` is not called, the miniport driver's **Technology** members are all set to KSMUSIC_TECHNOLOGY_PORT by default.

The following table lists the GUIDs that are defined for the *Technology* parameter and the corresponding integer value to which the **wTechnology** member of the MIDIOUTCAPS structure is set during a call to **midiOutGetDevCaps**.

| Technology GUID | MIDIOUTCAPS.wTechnology |
| --- | --- |
| KSMUSIC_TECHNOLOGY_PORT | MOD_MIDIPORT |
| KSMUSIC_TECHNOLOGY_SQSYNTH | MOD_SQSYNTH |
| KSMUSIC_TECHNOLOGY_FMSYNTH | MOD_FMSYNTH |
| KSMUSIC_TECHNOLOGY_WAVETABLE | MOD_WAVETABLE |
| KSMUSIC_TECHNOLOGY_SWSYNTH | MOD_SWSYNTH |

For more information, see [Music Technology GUIDs](https://learn.microsoft.com/windows-hardware/drivers/audio/music-technology-guids).

## See also

[IMusicTechnology](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-imusictechnology)

[KSDATARANGE_MUSIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdatarange_music)