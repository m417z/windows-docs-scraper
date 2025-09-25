# BuildCommDCBAndTimeoutsW function

## Description

Translates a device-definition string into appropriate device-control block codes and places them into
a device control block. The function can also set up time-out values, including the possibility of no
time-outs, for a device; the function's behavior in this regard depends on the contents of the device-definition
string.

## Parameters

### `lpDef` [in]

The device-control information. The function takes this string, parses it, and then sets appropriate values
in the [DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure pointed to by
*lpDCB*.

The string must have the same form as the **mode** command's command-line arguments:

**COM***x*[**:**][**baud=**{**11**|**110**|**15**|**150**|**30**|**300**|**60**|**600**|**12**|**1200**|**24**|**2400**|**48**|**4800**|**96**|**9600**|**19**|**19200**}][**parity=**{**n**|**e**|**o**|**m**|**s**}][**data=**{**5**|**6**|**7**|**8**}][**stop=**{**1**|**1.5**|**2**}][**to=**{**on**|**off**}][**xon=**{**on**|**off**}][**odsr=**{**on**|**off**}][**octs=**{**on**|**off**}][**dtr=**{**on**|**off**|**hs**}][**rts=**{**on**|**off**|**hs**|**tg**}][**idsr=**{**on**|**off**}]

The "baud" substring can be any of the values listed, which are in pairs. The two-digit
values are the first two digits of the associated values that they represent. For example, 11 represents 110 baud, 19
represents 19,200 baud.

The "parity" substring indicates how the parity bit is used to detect transmission errors.
The values represent "none", "even", "odd",
"mark", and "space".

For more information, see the [Mode](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/cc732236(v=ws.11)) command
reference in TechNet.

For example, the following string specifies a baud rate of 1200, no parity, 8 data bits, and 1 stop bit:

`baud=1200 parity=N data=8 stop=1`

### `lpDCB` [out]

A pointer to a [DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure that receives information
from the device-control information string pointed to by *lpDef*. This
**DCB** structure defines the control settings for a
communications device.

### `lpCommTimeouts` [out]

A pointer to a [COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts) structure that
receives time-out information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **BuildCommDCBAndTimeouts** function
modifies its time-out setting behavior based on the presence or absence of a "to={on|off}"
substring in *lpDef*:

* If that string contains the substring "to=on", the function sets the
  **WriteTotalTimeoutConstant** member of the
  [COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts) structure to 60000 and all other members
  to 0.
* If that string contains the substring "to=off", the function sets the members of
  [COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts) to 0.
* If that string does not specify a "to={on|off}" substring, the function ignores the
  [COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts) structure in
  *lpCommTimeouts*.

For more information, see the Remarks for the
[BuildCommDCB](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-buildcommdcba) function.

> [!NOTE]
> The winbase.h header defines BuildCommDCBAndTimeouts as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BuildCommDCB](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-buildcommdcba)

[COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb)

[GetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommtimeouts)

[SetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommtimeouts)