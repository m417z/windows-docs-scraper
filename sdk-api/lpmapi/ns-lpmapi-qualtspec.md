# QualTspec structure

## Description

The
**QualTspec** structure contains qualitative Tspec information.

## Members

### `qual_Tspec_serv_hdr`

General information and length information for the QualTspec object (this structure), expressed as an [IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr) structure.

### `qual_Tspec_parm_hdr`

Parameter header, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `qual_Tspec_parms`

Tspec parameters, expressed as a [QualTspecParms](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-qualtspecparms) structure.

## See also

[IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr)

[IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr)

[QualTspecParms](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-qualtspecparms)