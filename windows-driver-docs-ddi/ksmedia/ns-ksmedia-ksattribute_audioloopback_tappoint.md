# KSATTRIBUTE_AUDIOLOOPBACK_TAPPOINT structure (ksmedia.h)

## Description

The KSATTRIBUTE_AUDIOLOOPBACK_TAPPOINT attribute points to the pre and post tap audio point definitions. It is available starting in Windows 11 24H2.

## Members

### `AttributeHeader`

The AttributeHeader member specifies the attribute header using a [KSATTRIBUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksattribute) data type.

### `TapPoint`

The TapPoint member specifies the tap point type defined in the [AUDIOLOOPBACK_TAPPOINT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audioloopback_tappoint_type) enumeration.

## Remarks

The KSATTRIBUTE_AUDIOLOOPBACK_TAPPOINT structure available in ksmedia.h can provide a wrapper for specifying the AUDIO_LOOPBACK_TAPPOINT_TYPE attribute about where to tap loopback in the stream graph.

If KSATTRIBUTEID_AUDIOLOOPBACK_TAPPOINT is provided, then loopback should be collected based on options described by [AUDIOLOOPBACK_TAPPOINT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audioloopback_tappoint_type).

The *Ksmedia.h* header file defines the **KSATTRIBUTEID_AUDIOLOOPBACK_TAPPOINT** attribute ID as follows:

```cpp
#define STATIC_KSATTRIBUTEID_AUDIOLOOPBACK_TAPPOINT 0x2795a0f7, 0x1688, 0x44fe, 0xbc, 0x14, 0xbf, 0x82, 0x73, 0x99, 0x21, 0x41
DEFINE_GUIDSTRUCT("2795A0F7-1688-44FE-BC14-BF8273992141", KSATTRIBUTEID_AUDIOLOOPBACK_TAPPOINT);
#define KSATTRIBUTEID_AUDIOLOOPBACK_TAPPOINT DEFINE_GUIDNAMED(KSATTRIBUTEID_AUDIOLOOPBACK_TAPPOINT)
```

At pin creation time, a KSATTRIBUTEID_AUDIOLOOPBACK_TAPPOINT entry containing a KSATTRIBUTE_AUDIOLOOPBACK_TAPPOINT is added to the pin creation attributes. This entry contains the AUDIOLOOPBACK_TAPPOINT_TYPE for the loopback pin instance.

## See also

- [KSPROPERTY_AUDIOLOOPBACK](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioloopback)
- [KSPROPSETID_AudioLoopback](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-audioloopback)
- [AUDIOLOOPBACK_TAPPOINT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audioloopback_tappoint_type)