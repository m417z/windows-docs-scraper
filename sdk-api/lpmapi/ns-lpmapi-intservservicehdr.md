# IntServServiceHdr structure

## Description

The
**IntServServiceHdr** structure is a header for Integrated Services service objects.

## Members

### `issh_service`

Service number of the attached object.

### `issh_flags`

Flags for the corresponding service object.

### `issh_len32b`

Number of 32-bit WORDs in the object, excluding this header object.

## See also

[IntServMainHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservmainhdr)

[IntServParmHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservparmhdr)