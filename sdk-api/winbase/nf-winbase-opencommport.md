# OpenCommPort function

## Description

Attempts to open a communication device.

## Parameters

### `uPortNumber` [in]

A one-based port number for the communication device to open.

### `dwDesiredAccess` [in]

The requested access to the device.

For more information about requested access, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) and [Creating and Opening Files](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-opening-files).

### `dwFlagsAndAttributes` [in]

The requested flags and attributes to the device.

**Note**

For this function, only values of **FILE_FLAG_OVERLAPPED** or 0x0 are expected for this parameter.

| Value | Meaning |
| --- | --- |
| **FILE_FLAG_OVERLAPPED**<br><br>0x40000000 | The file or device is being opened or created for asynchronous I/O. |

## Return value

If the function succeeds, the function returns a valid **HANDLE**. Use [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) to close that handle.

If an error occurs, the function returns **INVALID_HANDLE_VALUE**.

## Remarks

The *uPortNumber* parameter accepts one-based values. A value of 1 for *uPortNumber* causes this function to attempt to open COM1.

To support UWP, link against WindowsApp.lib.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[Creating and Opening Files](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-opening-files)