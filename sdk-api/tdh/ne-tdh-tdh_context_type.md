# TDH_CONTEXT_TYPE enumeration

## Description

Defines the context type.

## Constants

### `TDH_CONTEXT_WPP_TMFFILE`

Null-terminated Unicode string that contains the name of the .tmf file used for parsing the WPP log. Typically, the .tmf file name is picked up from the event GUID so you do not have to specify the file name.

### `TDH_CONTEXT_WPP_TMFSEARCHPATH`

Null-terminated Unicode string that contains the path to the .tmf file. You do not have to specify this path if the search path contains the file. Only specify this context information if you also specify the TDH_CONTEXT_WPP_TMFFILE context type. If the file is not found, TDH searches the following locations in the given order:

* The path specified in the TRACE_FORMAT_SEARCH_PATH environment variable
* The current folder

### `TDH_CONTEXT_WPP_GMT`

A 1-byte Boolean flag that indicates if the WPP event time stamp should be converted to Universal Time Coordinate (UTC). If 1, the time stamp is converted to UTC. If 0, the time stamp is in local time. By default, the time stamp is in local time.

### `TDH_CONTEXT_POINTERSIZE`

Size, in bytes, of the pointer data types or size_t data types used in the event. Indicates if the event used 4-byte or 8-byte values. By default, the pointer size is the pointer size of the decoding computer.

To determine the size of the pointer or size_t value, use the **PointerSize** member of [TRACE_LOGFILE_HEADER](https://learn.microsoft.com/windows/desktop/ETW/trace-logfile-header) (the first event you receive in your [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback contains this header in the data section). However, this value may not be accurate. For example, on a 64-bit computer, a 32-bit application will log 4-byte pointers; however, the session will set **PointerSize** to 8.

### `TDH_CONTEXT_PDB_PATH`

Null-terminated Unicode string that contains the name of the .pdb file for the binary that contains WPP messages. This parameter can be used as an alternative to **TDH_CONTEXT_WPP_TMFFILE** or **TDH_CONTEXT_WPP_TMFSEARCHPATH**.

**Note** Available only for Windows 8 and Windows Server 2012.

### `TDH_CONTEXT_MAXIMUM`

Reserved.

## Remarks

If you are specifying context information for a legacy ETW event, you only need to specify the TDH_CONTEXT_POINTERSIZE type—the other types are used for WPP events and are ignored for legacy ETW events.

## See also
[TDH_CONTEXT](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-tdh_context)