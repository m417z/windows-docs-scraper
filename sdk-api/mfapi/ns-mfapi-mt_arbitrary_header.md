# MT_ARBITRARY_HEADER structure

## Description

Contains format data for a binary stream in an Advanced Streaming Format (ASF) file.

## Members

### `majortype`

Major media type. This value is the GUID stored in the Major Media Type field of the Type-Specific Data field of the ASF file. It might not match the major type GUID from the Media Foundation media type.

### `subtype`

Media subtype.

### `bFixedSizeSamples`

If **TRUE**, samples have a fixed size in bytes.
Otherwise, samples have variable size.

### `bTemporalCompression`

If **TRUE**, the data in this stream uses temporal compression. Otherwise, samples are independent of each other.

### `lSampleSize`

If **bFixedSizeSamples** is **TRUE**, this member specifies the sample size in bytes. Otherwise, the value is ignored and should be 0.

### `formattype`

Format type GUID. This GUID identifies the structure of the additional format data, which is stored in the
[MF_MT_ARBITRARY_FORMAT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-arbitrary-format) attribute of the media type. If no additional format data is present, **formattype** equals GUID_NULL.

## Remarks

This structure is used with the [MF_MT_ARBITRARY_HEADER](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-arbitrary-header) media type attribute.

This structure corresponds to the first 60 bytes of the Type-Specific Data field of the Stream Properties Object, in files where the stream type is ASF_Binary_Media. For more information, see the ASF specification.

The Format Data field of the Type-Specific Data field is contained in the [MF_MT_ARBITRARY_FORMAT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-arbitrary-format) attribute of the media type.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)