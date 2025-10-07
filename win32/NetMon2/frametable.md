# FRAMETABLE structure

The **FRAMETABLE** structure, a circular buffer of frame pointers, is handed back to applications attached to the **ITRC** interface of the NPP.

## Members

**FrameTableLength**

The total length of the table.

**StartIndex**

The first index within the table.

**EndIndex**

The last index within the table.

**FrameCount**

The number of frames described by this table.

**Frames**

The actual array of frame descriptors.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

