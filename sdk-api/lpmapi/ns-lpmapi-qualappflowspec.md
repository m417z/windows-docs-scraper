# QualAppFlowSpec structure

## Description

The
**QualAppFlowSpec** structure contains FLOWSPEC information for a qualitative application.

## Members

### `Q_spec_serv_hdr`

General information and length information for the QualAppFlowSpec object (this structure), expressed as an [IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr) structure.

### `Q_spec_parm_hdr`

Parameter header, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `Q_spec_parms`

QUALITATIVE Tspec parameters, expressed as a [QualTspecParms](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-qualtspecparms) structure.

## See also

[IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr)

[IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr)

[QualTspecParms](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-qualtspecparms)