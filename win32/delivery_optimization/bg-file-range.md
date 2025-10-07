# BG_FILE_RANGE structure

The **BG_FILE_RANGE** structure identifies a range of bytes to download from a file.

## Members

**InitialOffset**

Zero-based offset to the beginning of the range of bytes to download from a file.

**Length**

The length of the range, in bytes. Do not specify a zero byte length. To indicate that the range extends to the end of the file, specify **BG_LENGTH_TO_EOF**.

## Remarks

The range must exist in the file or Delivery Optimization generates an **DO_E_INVALID_RANGE** error.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**IBackgroundCopyFile2::GetFileRanges**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyfile2-getfileranges-method)

