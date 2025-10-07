# EXPERTENUMINFO structure

The **EXPERTENUMINFO** structure provides information about the expert. Network Monitor allocates memory for the structure, and passes it to the expert when it calls the [**Register Expert**](https://learn.microsoft.com/windows/win32/netmon2/register-expert) function. When the expert receives the structure, it must then fill-in all the information that Network Monitor requests.

## Members

**szName**

Name of the expert.

**szVendor**

Name of the vendor that creates the expert.

**szDescription**

Description of the expert. The value of the **szDescription** member may be **NULL**. If the name is too long, it is truncated in the default viewer configuration.

**Version**

The value must be zero.

**Flags**

The following flags describe the expert.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
|

**EXPERT\_ENUM\_FLAG\_CONFIGURABLE**

| The expert supports calls to the [**Configure**](https://learn.microsoft.com/windows/win32/netmon2/configure) method. <br> |
|

**EXPERT\_ENUM\_FLAG\_VIEWER\_PRIVATE**

| The expert requires a private (non-shared) Event Viewer. <br> |
|

**EXPERT\_ENUM\_FLAG\_NO\_VIEWER**

| The expert does not send event notifications. <br> |
|

**EXPERT\_ENUM\_FLAG\_ADD\_ME\_TO\_RMC\_IN\_SUMMARY**

| When the focus is in the summary pane, the expert appears on the context menu. <br> |
|

**EXPERT\_ENUM\_FLAG\_ADD\_ME\_TO\_RMC\_IN\_DETAIL**

| When the focus is in the detail pane, the expert appears on the context menu. <br> |

**hExpert**

Handle to the expert. When the **EXPERTENUMINFO** structure is used to register an expert, the parameter is ignored.

**szDllName**

Private member; do not use.

**hModule**

Private member; do not use.

**pRegisterProc**

Private member; do not use.

**pConfigProc**

Private member; do not use.

**pRunProc**

Private member; do not use.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

