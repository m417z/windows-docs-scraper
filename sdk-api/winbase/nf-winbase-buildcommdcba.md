# BuildCommDCBA function

## Description

Fills a specified
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure with values specified in a device-control string. The device-control string uses the syntax of the **mode** command.

## Parameters

### `lpDef` [in]

The device-control information. The function takes this string, parses it, and then sets appropriate values in the
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure pointed to by *lpDCB*.

The string must have the same form as the **mode** command's command-line arguments:

COM*x*[:][baud=*b*][parity=*p*][data=*d*][stop=*s*][to={on|off}][xon={on|off}][odsr={on|off}][octs={on|off}][dtr={on|off|hs}][rts={on|off|hs|tg}][idsr={on|off}]

The device name is optional, but it must specify a valid device if used.

For example, the following string specifies a baud rate of 1200, no parity, 8 data bits, and 1 stop bit:

`baud=1200 parity=N data=8 stop=1`

### `lpDCB` [out]

A pointer to a
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure that receives the information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**BuildCommDCB** function adjusts only those members of the
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure that are specifically affected by the *lpDef* parameter, with the following exceptions:

* If the specified baud rate is 110, the function sets the stop bits to 2 to remain compatible with the system's **mode** command.
* By default,
  **BuildCommDCB** disables XON/XOFF and hardware flow control. To enable flow control, you must explicitly set the appropriate members of the
  [DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure.

The
**BuildCommDCB** function only fills in the members of the
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure. To apply these settings to a serial port, use the
[SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate) function.

There are older and newer forms of the **mode** syntax. The
**BuildCommDCB** function supports both forms. However, you cannot mix the two forms together.

The newer form of the **mode** syntax lets you explicitly set the values of the flow control members of the
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure. If you use an older form of the **mode** syntax, the
**BuildCommDCB** function sets the flow control members of the
**DCB** structure, as follows:

* For a string that does not end with an x or a p:

  + **fInX**, **fOutX**, **fOutXDsrFlow**, and **fOutXCtsFlow** are all set to **FALSE**
  + **fDtrControl** is set to DTR_CONTROL_ENABLE
  + **fRtsControl** is set to RTS_CONTROL_ENABLE
* For a string that ends with an x:

  + **fInX** and **fOutX** are both set to **TRUE**
  + **fOutXDsrFlow** and **fOutXCtsFlow** are both set to **FALSE**
  + **fDtrControl** is set to DTR_CONTROL_ENABLE
  + **fRtsControl** is set to RTS_CONTROL_ENABLE
* For a string that ends with a p:

  + **fInX** and **fOutX** are both set to **FALSE**
  + **fOutXDsrFlow** and **fOutXCtsFlow** are both set to **TRUE**
  + **fDtrControl** is set to DTR_CONTROL_HANDSHAKE
  + **fRtsControl** is set to RTS_CONTROL_HANDSHAKE

> [!NOTE]
> The winbase.h header defines BuildCommDCB as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb)

[SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate)