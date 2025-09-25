# DD_MORESURFACECAPS structure

## Description

The DD_MORESURFACECAPS structure defines more driver surface capabilities in addition to those described in [DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps).

## Members

### `dwSize`

Specifies the size of this DD_MORESURFACECAPS structure. The DD_MORESURFACECAPS structure is of variable size. There should be exactly **DD_HALINFO.vmiData.dwNumHeaps** copies of the **ddsExtendedHeapRestrictions** structure within the array member of this structure. The total size of a DD_MORESURFACECAPS structure is thus:

```
dwSize =
   sizeof(DD_MORESURFACECAPS) +
   (DD_HALINFO.vmiData.dwNumHeaps - 1) * sizeof(DDSCAPSEX) * 2
```

This calculation accounts for the minimum size of the DD_MORESURFACECAPS structure, which includes only one **ddsExtendedHeapRestrictions** array element. Any additional **ddsExtendedHeapRestrictions** array elements must be accounted for by adding the sizes of the remaining array elements. That is, by adding the product of the number of remaining **ddsExtendedHeapRestrictions** structures times the size of each one.

### `ddsCapsMore`

Specifies a DDSCAPSEX structure that provides the extensions to **ddcaps.ddsCaps** that describe the types of extended surfaces the driver can create. When a DDCAPS structure is returned to the application, it is a [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure manufactured from **DDCAPS.ddsCaps** and **DD_MORESURFACECAPS.ddsCapsMore**. A DDSCAPSEX structure is the same as a DDSCAPS2 structure without the **dwCaps** member.

### `tagNTExtendedHeapRestrictions`

### `tagNTExtendedHeapRestrictions.ddsCapsExAlt`

### `ddsExtendedHeapRestrictions`

Specifies a structure containing two members. These members are filled in by Microsoft DirectX 6.0-aware drivers (and drivers compliant with later versions of DirectX), to restrict the video memory heaps that are exposed to Microsoft DirectDraw to certain sets of DDSCAPS_*Xxx* bits. The DirectDraw version is determined by looking at DDVERSIONINFO, which is defined in *ddrawi.h*. The **ddsCapsEx** and **ddsCapsExAlt** members of the DD_MORESURFACECAPS structure are exactly analogous to the **ddsCaps** and **ddsCapsAlt** members of the VIDEOMEMORY structures listed in the **VIDMEMINFO.pvmList** member of **DD_HALINFO.vmiData**.

#### ddsCapsEx

Specifies a DDSCAPSEX structure in which the driver returns the capabilities for which this chunk of memory cannot be used.

#### ddsCapsExAlt

Specifies a DDSCAPSEX structure in which the driver returns the capabilities for which this chunk of memory cannot be used for when no other memory is found on the first pass.

## Remarks

This structure contains the caps bits added to the **DDCAPS.ddsCaps** structure in DirectX 6.0. See the DirectDraw SDK documentation for a description of the DDCAPS structure.

**Note for Microsoft Windows 98/Me:** DD_MORESURFACECAPS is the definition for Windows 2000 and later versions. Drivers that run on Windows 98/Me use the name DDMORESURFACECAPS, which is aliased in *dx95type.h*.

## See also

[DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps)

[DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85))