# LINECALLTREATMENTENTRY structure

## Description

The
**LINECALLTREATMENTENTRY** structure provides information on the type of call treatment, such as music, recorded announcement, or silence, on the current call. The
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) structure can contain an array of
**LINECALLTREATMENTENTRY** structures.

## Members

### `dwCallTreatmentID`

One of the
[LINECALLTREATMENT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecalltreatment--constants) (if the treatment is of a predefined type) or a service provider-specific value.

### `dwCallTreatmentNameSize`

Size of the call treatment name string, in bytes, including the null-terminating character.

### `dwCallTreatmentNameOffset`

Offset from the beginning of
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) to a null-terminated string identifying the treatment. This would ordinarily describe the content of the music or recorded announcement. If the treatment is of a predefined type, a meaningful name should still be specified, for example, "Silence\0", "Busy Signal\0", "Ringback\0", or "Music\0". The size of the string is specified by **dwCallTreatmentNameOffset**.

## See also

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINECALLTREATMENT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecalltreatment--constants)

[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps)

[lineSetCallTreatment](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcalltreatment)