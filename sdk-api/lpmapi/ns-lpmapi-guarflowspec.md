# GuarFlowSpec structure

## Description

The
**GuarFlowSpec** structure contains guaranteed flowspec information.

## Members

### `Guar_serv_hdr`

General information and length information for the guaranteed flowspec object (this structure), expressed as an [IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr) structure.

### `Guar_Tspec_hdr`

Parameter header for the guaranteed Tspec, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `Guar_Tspec_parms`

Generic Tspec parameters, expressed as a [GenTspecParms](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-gentspecparms) structure.

### `Guar_Rspec_hdr`

Parameter header for the guaranteed Rspec, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `Guar_Rspec`

Guaranteed rate, in bytes per second, expressed as a [GuarRspec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-guarrspec) structure.

## See also

[GenTspecParms](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-gentspecparms)

[GuarRspec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-guarrspec)

[IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr)

[IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr)