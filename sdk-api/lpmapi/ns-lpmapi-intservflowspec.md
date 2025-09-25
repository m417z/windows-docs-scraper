# IntServFlowSpec structure

## Description

The
**IntServFlowSpec** structure contains information about Integrated Services flowspecs.

## Members

### `spec_mh`

General information and length information for the flowspec object (this structure), expressed as an [IntServMainHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservmainhdr) structure.

### `spec_u`

Union containing flowspec information.

#### CL_spec

Controlled load flowspec information, expressed as a [CtrlLoadFlowspec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-ctrlloadflowspec) structure.

#### G_spec

Guaranteed service flowspec information, expressed as a [GuarFlowSpec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-guarflowspec) structure.

#### Q_spec

Qualitative application flowspec information, expressed as a [QualAppFlowSpec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-qualappflowspec) structure.

### `CL_spec`

### `G_spec`

### `Q_spec`

## See also

[CtrlLoadFlowspec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-ctrlloadflowspec)

[GuarFlowSpec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-guarflowspec)

[QualAppFlowSpec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-qualappflowspec)