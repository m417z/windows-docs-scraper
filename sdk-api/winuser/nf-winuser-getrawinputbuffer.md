# GetRawInputBuffer function

## Description

Performs a buffered read of the raw input messages data found in the calling thread's message queue.

## Parameters

### `pData` [out, optional]

Type: **PRAWINPUT**

A pointer to a buffer of [RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput) structures that contain the raw input data. Pointer should be aligned on a **DWORD** (32-bit) boundary.

If **NULL**, size of the first raw input message data (minimum required buffer), in bytes, is returned in \**pcbSize*.

### `pcbSize` [in, out]

Type: **PUINT**

The size, in bytes, of the provided [RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput) buffer.

### `cbSizeHeader` [in]

Type: **UINT**

The size, in bytes, of the [RAWINPUTHEADER](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinputheader) structure.

## Return value

Type: **UINT**

If *pData* is **NULL** and the function is successful, the return value is zero. If *pData* is not **NULL** and the function is successful, the return value is the number of [RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput) structures written to *pData*.

If an error occurs, the return value is (**UINT**)-1. Call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) for the error code.

## Remarks

When an application receives raw input, its message queue gets a [WM_INPUT](https://learn.microsoft.com/windows/win32/inputdev/wm-input) message and the queue status flag [QS_RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getqueuestatus) is set.

Using **GetRawInputBuffer**, the raw input data is read in the array of variable size [RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput) structures and corresponding [WM_INPUT](https://learn.microsoft.com/windows/win32/inputdev/wm-input) messages are removed from the calling thread's message queue. You can call this method several times with buffer that cannot fit all message's data until all raw input messages have been read.

The [NEXTRAWINPUTBLOCK](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-nextrawinputblock) macro allows an application to traverse an array of [RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput) structures.

If all raw input messages have been successfully read from message queue then [QS_RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getqueuestatus) flag is cleared from the calling thread's message queue status.

> [!NOTE]
> WOW64: To get the correct size of the raw input buffer, do not use \**pcbSize*, use \**pcbSize* \* 8 instead. To ensure **GetRawInputBuffer** behaves properly on WOW64, you must align the [RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput) structure by 8 bytes. The following code shows how to align **RAWINPUT** for WOW64.

```csharp
[StructLayout(LayoutKind.Explicit)]
internal struct RAWINPUT
{
    [FieldOffset(0)]
    public RAWINPUTHEADER header;

    [FieldOffset(16+8)]
    public RAWMOUSE mouse;

    [FieldOffset(16+8)]
    public RAWKEYBOARD keyboard;

    [FieldOffset(16+8)]
    public RAWHID hid;
}
```

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getmessage)

[NEXTRAWINPUTBLOCK](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-nextrawinputblock)

[RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput)

[RAWINPUTHEADER](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinputheader)

[Raw Input](https://learn.microsoft.com/windows/win32/inputdev/raw-input)

**Reference**

[Raw Input Overview](https://learn.microsoft.com/windows/win32/inputdev/about-raw-input)