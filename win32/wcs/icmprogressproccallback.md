# ICMProgressProcCallback callback function

The **ICMProgressProcCallback** function is an application-supplied callback function that reports progress and permits the application to cancel color processing.

## Parameters

*ulMax*

Specifies the maximum value of the progress counter (used to estimate completion of the bitmap processing).

*ulCurrent*

Specifies the current value of the progress counter (when divided by the maximum value, provides a rough estimate of percentage of completion).

*ulCallbackData*

Specifies the data which is passed by the application to an ICM2 function, which then passes it on to the callback function. Such data can be used, for example, to identify the bitmap and process about which progress is being reported.

## Return value

This function returns **TRUE** to continue bitmap processing. The return value is **FALSE** to cancel processing. If processing is canceled, the calling function returns zero to indicate failure, although its output buffer may be partially filled.

## Remarks

The name of this callback function is supplied by the application. A number of WCS functions, including [**TranslateBitmapBits**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-translatebitmapbits) and [**CheckBitmapBits**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-checkbitmapbits), call this function periodically.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Icm.h |

## See also

[Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)

[Functions](https://learn.microsoft.com/windows/win32/wcs/functions)

[**TranslateBitmapBits**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-translatebitmapbits)

[**CheckBitmapBits**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-checkbitmapbits)