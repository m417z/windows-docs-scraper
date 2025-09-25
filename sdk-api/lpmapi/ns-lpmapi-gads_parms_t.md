# Gads_parms_t structure

## Description

The
**Gads_parms_t** structure stores guaranteed service Adspec parameters.

## Members

### `Gads_serv_hdr`

General information and length information for the guaranteed service Adspec object (this structure), expressed as an [IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr) structure.

### `Gads_Ctot_hdr`

Parameter header for the guaranteed service Adspec, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `Gads_Ctot`

Parameter associated with **Gads_Ctot_hdr**.

### `Gads_Dtot_hdr`

Parameter header for the guaranteed service Adspec, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `Gads_Dtot`

Parameter associated with **Gads_Dtot_hdr**.

### `Gads_Csum_hdr`

Parameter header for the guaranteed service Adspec, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `Gads_Csum`

Parameter associated with **Gads_Csum**.

### `Gads_Dsum_hdr`

Parameter header for the guaranteed service Adspec, expressed as an [IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr) structure.

### `Gads_Dsum`

Parameter associated with **Gads_Dsum**.

## Remarks

This object may be followed by override general parameter values.

## See also

[IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr)

[IntServServiceHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservservicehdr)