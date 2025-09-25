# GenAdspecParams structure

## Description

The
**GenAdspecParams** structure contains general path characterization parameters.

## Members

### `gen_parm_hdr`

General information and length information for the Adspec parameters object (this structure), expressed as an [IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr) structure.

### `gen_parm_hopcnt_hdr`

Parameter header for hop count information associated with the Adspec object, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `gen_parm_hopcnt`

Hop count information parameter.

### `gen_parm_pathbw_hdr`

Parameter header for path bandwidth information associated with the Adspec object, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `gen_parm_path_bw`

Path bandwidth information parameter.

### `gen_parm_minlat_hdr`

Parameter header for minimum latency information associated with the Adspec object, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `gen_parm_min_latency`

Minimum latency information parameter.

### `gen_parm_compmtu_hdr`

Parameter header for composed maximum transmission unit (MTU) information associated with the Adspec object, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `gen_parm_composed_MTU`

Composed MTU information parameter.

## See also

[IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr)

[IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr)