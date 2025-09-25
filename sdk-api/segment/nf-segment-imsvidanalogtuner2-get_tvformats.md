# IMSVidAnalogTuner2::get_TVFormats

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **get_TVFormats** method retrieves a flag value that indicates which TV formats the tuner supports, such as NTSC, PAL, or SECAM.

## Parameters

### `Formats` [out]

Pointer to a variable that receives the formats flag. Possible values are the sum of one or more of the values in the following table.

| Value | Description |
| --- | --- |
| 0x00000000 | Digital sensor |
| 0x00000001 | NTSC (M) standard, 7.5 IRE black |
| 0x00000002 | NTSC (M) standard, 0 IRE black (Japan) |
| 0x00000004 | NTSC-433 |
| 0x00000010 | PAL-B standard |
| 0x00000020 | PAL (D) standard |
| 0x00000080 | PAL (H) standard |
| 0x00000100 | PAL (I) standard |
| 0x00000200 | PAL (M) standard |
| 0x00000400 | PAL (N) standard |
| 0x00000800 | PAL-60 standard |
| 0x00001000 | SECAM (B) standard |
| 0x00002000 | SECAM (D) standard |
| 0x00004000 | SECAM (G) standard |
| 0x00008000 | SECAM (H) standard |
| 0x00010000 | SECAM (K) standard |
| 0x00020000 | SECAM (K1) standard |
| 0x00040000 | SECAM (L) standard |
| 0x00080000 | SECAM (L1) standard |
| 0x00100000 | Combination (N) PAL standard (Argentina) |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

## See also

[IMSVidAnalogTuner2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidanalogtuner2)