# IntServTspecBody structure

## Description

The
**IntServTspecBody** structure contains information for an RSVP Tspec.

## Members

### `st_mh`

Header for the corresponding Tspec object, expressed as [IntServMainHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservmainhdr) structure.

### `tspec_u`

#### gen_stspec

Generic Tspec, expressed as a [GenTspec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-gentspec) structure.

#### qual_stspec

Qualitative Tspec, expressed as a [QualTspec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-qualtspec) structure.

### `gen_stspec`

### `qual_stspec`

## See also

[GenTspec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-gentspec)

[IntServMainHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservmainhdr)

[QualTspec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-qualtspec)