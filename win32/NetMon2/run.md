# Run callback function

The expert must implement the **Run** function. Network Monitor calls the **Run** function to start the expert within the expert DLL.

## Parameters

*hExpertKey* \[in\]

Unique identifier of the expert that is passed back to all expert-specific Network Monitor functions.

> [!Note]
> The *hExpertKey* identifier may pass an expert key that is different from the expert key that the [**Configure**](https://learn.microsoft.com/windows/win32/netmon2/configure) function passes.

*pConfig* \[in\]

Pointer to the existing configuration. The *pConfig* parameter may be **NULL** which means that the expert can run with hard-coded defaults, or startup information that the *pExpertStartupInfo* parameter references.

*pExpertStartupInfo* \[in\]

Pointer to the capture element that has focus when the expert starts.

*StartupFlags* \[in\]

Indicator for how the expert should use the *pExpertStartupInfo* parameter.

The only flag defined is:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**EXPERT\_STARTUP\_FLAG\_USE\_STARTUP\_DATA\_OVER\_CONFIG\_DATA.**

| This flag indicates that the expert uses the *pExpertStartupInfo* parameter, and does not use the *pConfig* parameter. Typically, you can set this flag when the expert can start from a right-mouse click. If the flag is not set, the following two things can occur: either the expert does not start from a right-mouse click, or the expert starts from a right-mouse click, and then the user configures it.<br> |

*hWndParent* \[in\]

The *hWnd* parameter of the parent (usually the Network Monitor user interface).

## Return value

If the function is successful (that is, if the expert starts), the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Remarks

When running, the expert loops through the frames in the capture file and either generates a report or creates events that show problems.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

