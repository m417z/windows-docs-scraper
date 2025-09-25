# COMMTIMEOUTS structure

## Description

Contains the time-out parameters for a communications device. The parameters determine the
behavior of [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile),
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile),
[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex), and
[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) operations on the device.

## Members

### `ReadIntervalTimeout`

The maximum time allowed to elapse before the arrival of the next byte on the communications line, in
milliseconds. If the interval between the arrival of any two bytes exceeds this amount, the
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) operation is completed and any buffered data is
returned. A value of zero indicates that interval time-outs are not used.

A value of **MAXDWORD**, combined with zero values for both the
**ReadTotalTimeoutConstant** and **ReadTotalTimeoutMultiplier**
members, specifies that the read operation is to return immediately with the bytes that have already been
received, even if no bytes have been received.

### `ReadTotalTimeoutMultiplier`

The multiplier used to calculate the total time-out period for read operations, in milliseconds. For each
read operation, this value is multiplied by the requested number of bytes to be read.

### `ReadTotalTimeoutConstant`

A constant used to calculate the total time-out period for read operations, in milliseconds. For each read
operation, this value is added to the product of the **ReadTotalTimeoutMultiplier**
member and the requested number of bytes.

A value of zero for both the **ReadTotalTimeoutMultiplier** and
**ReadTotalTimeoutConstant** members indicates that total time-outs are not used for
read operations.

### `WriteTotalTimeoutMultiplier`

The multiplier used to calculate the total time-out period for write operations, in milliseconds. For each
write operation, this value is multiplied by the number of bytes to be written.

### `WriteTotalTimeoutConstant`

A constant used to calculate the total time-out period for write operations, in milliseconds. For each write
operation, this value is added to the product of the **WriteTotalTimeoutMultiplier**
member and the number of bytes to be written.

A value of zero for both the **WriteTotalTimeoutMultiplier** and
**WriteTotalTimeoutConstant** members indicates that total time-outs are not used for
write operations.

## Remarks

If an application sets **ReadIntervalTimeout** and
**ReadTotalTimeoutMultiplier** to **MAXDWORD** and sets
**ReadTotalTimeoutConstant** to a value greater than zero and less than
**MAXDWORD**, one of the following occurs when the
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) function is called:

* If there are any bytes in the input buffer,
  [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) returns immediately with the bytes in the
  buffer.
* If there are no bytes in the input buffer, [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)
  waits until a byte arrives and then returns immediately.
* If no bytes arrive within the time specified by **ReadTotalTimeoutConstant**,
  [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) times out.

## See also

[GetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommtimeouts)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex)

[SetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommtimeouts)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)