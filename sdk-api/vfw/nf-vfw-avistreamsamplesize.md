# AVIStreamSampleSize macro

## Syntax

```cpp
HRESULT AVIStreamSampleSize(
     pavi,
     lPos,
     plSize
);
```

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns zero if successful or an error otherwise. Possible error values include the following:

|  |  |
| --- | --- |
| AVIERR_BUFFERTOOSMALL | The buffer size was smaller than a single sample of data. |
| AVIERR_MEMORY | There was not enough memory to complete the read operation. |
| AVIERR_FILEREAD | A disk error occurred while reading the file. |

## Description

The [AVIStreamRelease](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamrelease) macro determines the size of the buffer needed to store one sample of information from a stream. The size corresponds to the sample at the position specified by *lPos*.

## Parameters

### `pavi`

Handle to an open stream.

### `lPos`

Position of a sample in the stream.

### `plSize`

Address to contain the buffer size.

## Remarks

The **AVIStreamSampleSize** macro is defined as follows:

```cpp

#define AVIStreamSampleSize(pavi, lPos, plSize) \
    AVIStreamRead(pavi, lPos, 1, NULL, 0, plSize, NULL)

```

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-macros)