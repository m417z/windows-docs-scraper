# MINIDUMP_IO_CALLBACK structure

## Description

Contains I/O callback information. This structure is used by the [MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) function when the callback type is **IoStartCallback**, **IoWriteAllCallback**, or **IoFinishCallback**.

## Members

### `Handle`

The file handle passed to the [MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function.

### `Offset`

The offset for the write operation from the start of the minidump data. This member is used only with **IoWriteAllCallback**.

### `Buffer`

A pointer to a buffer that contains the data to be written. This member is used only with **IoWriteAllCallback**.

### `BufferBytes`

The size of the data buffer, in bytes. This member is used only with **IoWriteAllCallback**.

## See also

[MINIDUMP_CALLBACK_INPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_input)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)