# EXPERTSTARTUPINFO structure

The **EXPERTSTARTUPINFO** structure contains data that describes an expert when it starts.

## Members

**Flags**

Flags that describe the expert.

**hCapture**

Handle to a capture.

**szCaptureFile**

Name of the capture file.

**dwFrameNumber**

Frame number.

**hProtocol**

Handle to the protocol.

**lpPropertyInst**

Pointer to a [**PROPERTYINST**](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structure.

**sBitfield**

**BitNumber**

Used only if the **DataQualifier** member of the [**PROPERTYINST**](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structure is set to PROP\_QUAL\_FLAGS.

**bOn**

Used only if the **DataQualifier** member of the [**PROPERTYINST**](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structure is set to PROP\_QUAL\_FLAGS.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

