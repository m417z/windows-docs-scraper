# BG_FILE_RANGE structure

## Description

Identifies a range of bytes to download from a file.

## Members

### `InitialOffset`

Zero-based offset to the beginning of the range of bytes to download from a file.

### `Length`

The length of the range, in bytes. Do not specify a zero byte length. To indicate that the range extends to the end of the file, specify **BG_LENGTH_TO_EOF**.

## Remarks

The range must exist in the file or BITS generates an **BG_E_INVALID_RANGE** error.

## See also

[IBackgroundCopyFile2::GetFileRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyfile2-getfileranges)

[IBackgroundCopyJob3::AddFileWithRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-addfilewithranges)