# IS_ADSPEC_BODY structure

## Description

The
**IS_ADSPEC_BODY** structure contains Integrated Services Adspec information.

## Members

### `adspec_mh`

Main header information and length, expressed as an [IntServMainHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservmainhdr) structure.

### `adspec_genparms`

General Adspec parameter fragment, followed by variable-length fragments for some or all services.

## Remarks

The variable-length fragments that follow the **adspec_genparams** member can be minimal length fragments.

## See also

[IntServMainHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservmainhdr)