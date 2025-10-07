# MsimtfIsWindowFiltered function

The **MsimtfIsWindowFiltered** function tests if the given window is filtered by AIMM (Active Input Method Manager).

## Parameters

*hwnd* \[in\]

A window handle to be tested.

## Return value

| Return code | Description |
|--------------------------------------------------------------------------------------|---------------------------------------------------------------------------|
| **TRUE** | If this window is filtered by Active Input Method Manager.<br> |
| **FALSE** | If this window is not filtered by Active Input Method Manager.<br> |

## Remarks

A window can be filtered by IActiveIMMApp::FilterClientWindows.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Msimtf.dll |

