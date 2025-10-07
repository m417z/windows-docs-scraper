# FRAME\_DESCRIPTOR structure

The **FRAME\_DESCRIPTOR** structure provides descriptive information about raw frames.

## Members

**FramePointer**

Pointer to frame data.

**TimeStamp**

System time, in microseconds, when the frame was captured. This time is typically used to determine the interval between the times two frames were captured.

**FrameLength**

Length of the frame.

**nBytesAvail**

Actual frame length copied.

**Etype**

Etype name.

**Sap**

SAP value.

**LowProtocol**

Index of protocol found.

**LowProtocolOffset**

Offset to protocol data obtained from **LowProtocol**.

**HighPort**

Port of high protocol identified in **LowProtocol**.

**HighProtocolOffset**

Offset to protocol data obtained from **HighPort**.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

