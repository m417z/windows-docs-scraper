# CAPTUREFILE\_HEADER\_VALUES structure

The **CAPTUREFILE\_HEADER\_VALUES** structure defines the Network Monitor header file structure.

## Members

**Signature**

Unique identifier: 'GMBU.

**BCDVerMinor**

Binary, coded decimal (minor). The value of this member should be zero (0).

**BCDVerMajor**

Binary coded decimal (major). This value should be 2.

**MacType**

Topology type.

**TimeStamp**

Time of capture.

**FrameTableOffset**

Frame index table.

**FrameTableLength**

Frame index table size.

**UserDataOffset**

User data offset.

**UserDataLength**

User data length.

**CommentDataOffset**

Comment data offset.

**CommentDataLength**

Length of comment data.

**StatisticsOffset**

Offset to the **STATISTICS** structure.

**StatisticsLength**

Length of the **STATISTICS** structure.

**NetworkInfoOffset**

Offset to the **NETWORKINFO** structure.

**NetworkInfoLength**

Length of the **NETWORKINFO** structure.

**ConversationStatsOffset**

This member is not used.

**ConversationStatsLength**

This member is not used.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

