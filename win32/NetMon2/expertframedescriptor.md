# EXPERTFRAMEDESCRIPTOR structure

The **EXPERTFRAMEDESCRIPTOR** structure contains information about a frame. When the expert calls the [**ExpertGetFrame**](https://learn.microsoft.com/windows/win32/netmon2/expertgetframe) function successfully, Network Monitor passes the **EXPERTFRAMEDESCRIPTOR** structure back to the expert.

## Members

**FrameNumber**

Number of a specified frame.

**hFrame**

Handle to a frame.

**pFrame**

Pointer to a raw frame.

**lpRecognizeDataTable**

Table that indicates where each parser identifies the start of the data.

**lpPropertyTable**

Table of frame properties that the parser identifies.

## Remarks

If the expert specifies FLAGS\_ATTACH\_PROPERTIES when calling [**ExpertGetFrame**](https://learn.microsoft.com/windows/win32/netmon2/expertgetframe), then the **szPropertyText** member in each [**PROPERTYINST**](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structure is **NULL**.

If the expert does not specify FLAGS\_ATTACH\_PROPERTIES when calling the [**ExpertGetFrame**](https://learn.microsoft.com/windows/win32/netmon2/expertgetframe) function, then the **lpPropertyTable** member is **NULL** on return.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

