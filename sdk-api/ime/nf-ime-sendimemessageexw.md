# SendIMEMessageExW function

## Description

[This function is obsolete and should not be used.]

Specifies an action or processing for the Input Method Editor (IME) through a specified subfunction.

## Parameters

### `HWND` [in]

The window handle of the application that initiates the transaction. Generally, it is the window that has focus.

### `LPARAM` [in]

A **DWORD** value in which the low-order word specifies a handle to the global memory that contains an [IMESTRUCT](https://learn.microsoft.com/windows/desktop/api/ime/ns-ime-imestruct) structure. The global memory is allocated by specifying the **GMEM_MOVEABLE** and **GMEM_SHARE** flags in the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function. The high-order word is reserved; it is not used.

## Return value

The result of processing of the subfunction. If the result is not success, one of the following error codes is stored into the **wParam** of the [IMESTRUCT](https://learn.microsoft.com/windows/desktop/api/ime/ns-ime-imestruct) structure.

| Return code | Description |
| --- | --- |
| **IME_RS_DISKERROR** | Disk error. |
| **IME_RS_ERROR** | General error. |
| **IME_RS_ILLEGAL** | Contains an illegal character. |
| **IME_RS_INVALID** | Invalid subfunction. |
| **IME_RS_NEST** | Subfunction is nested and, therefore, cannot be used. |
| **IME_RS_NOIME** | The IME has not been selected (has not been installed). |
| **IME_RS_NOROOM** | Short of area. |
| **IME_RS_NOTFOUND** | No candidate found. |
| **IME_RS_SYSTEMMODAL** | Windows is in system mode, data cannot be passed to the IME. |
| **IME_RS_TOOLONG** | Characters too long. |

## Remarks

**SendIMEMessageEx** guarantees the action stipulated in the specifications only for IMEs that support the **WM_CONVERTREQUESTEX** message. For an IME that does not support **WM_CONVERTREQUESTEX**, **SendIMEMessageEx** sends a **WM_CONVERTREQUEST** message to the IME and returns the contents of the **wParam** member of the [IMESTRUCT](https://learn.microsoft.com/windows/desktop/api/ime/ns-ime-imestruct) structure. If the processing of the subfunction has not been completed normally, these functions set **IME_RS_ERROR** into **wParam**.

> [!NOTE]
> The ime.h header defines SendIMEMessageEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).