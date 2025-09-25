# CtrlLoadFlowspec structure

## Description

The
**CtrlLoadFlowspec** structure contains a Controlled Load FLOWSPEC.

## Members

### `CL_spec_serv_hdr`

General information and length information for the controlled load flowspec object (this structure), expressed as an [IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr) structure.

### `CL_spec_parm_hdr`

Parameter header, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `CL_spec_parms`

Generic Tspec parameters, expressed as a [GenTspecParms](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-gentspecparms) structure.

## See also

[GenTspecParms](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-gentspecparms)

[IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr)

[IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr)