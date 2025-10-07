# \_VIDEOINFOHEADER structure

The **\_VIDEOINFOHEADER** structure contains information about a video stream and includes a **\_BITMAPINFOHEADER** structure that defines the format of an individual frame.

## Members

**rcSource**

**RECT** structure that specifies the source video window.

**rcTarget**

**RECT** structure that specifies the destination video window.

**dwBitRate**

**DWORD** value that specifies the video stream's approximate data rate, in bits per second.

**dwBitErrorRate**

**DWORD** value that specifies the video stream's data error rate, in bit errors per second.

**AvgTimePerFrame**

**REFERENCE\_TIME** value that specifies the video frame's average display time, in 100-nanosecond units.

**bmiHeader**

Win32 **\_BITMAPINFOHEADER** structure that contains color and dimension information for the video image bitmap.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**\_BITMAPINFOHEADER**](https://learn.microsoft.com/windows/win32/wmdm/-bitmapinfoheader)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

