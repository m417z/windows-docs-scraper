# GetUserObjectInformationW function

## Description

Retrieves information about the specified window station or desktop object.

## Parameters

### `hObj` [in]

A handle to the window station or desktop object. This handle is returned by the
[CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa),
[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa),
[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa), or
[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa) function.

### `nIndex` [in]

The information to be retrieved. The parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **UOI_FLAGS**<br><br>1 | The handle flags. The *pvInfo* parameter must point to a [USEROBJECTFLAGS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-userobjectflags) structure. |
| **UOI_HEAPSIZE**<br><br>5 | The size of the desktop heap, in KB, as a **ULONG** value. The *hObj* parameter must be a handle to a desktop object, otherwise, the function fails.<br><br>**Windows Server 2003 and Windows XP/2000:** This value is not supported. |
| **UOI_IO**<br><br>6 | **TRUE** if the *hObj* parameter is a handle to the desktop object that is receiving input from the user. **FALSE** otherwise.<br><br>**Windows Server 2003 and Windows XP/2000:** This value is not supported. |
| **UOI_NAME**<br><br>2 | The name of the object, as a string. |
| **UOI_TYPE**<br><br>3 | The type name of the object, as a string. |
| **UOI_USER_SID**<br><br>4 | The [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that identifies the user that is currently associated with the specified object. If no user is associated with the object, the value returned in the buffer pointed to by *lpnLengthNeeded* is zero. Note that **SID** is a variable length structure. You will usually make a call to **GetUserObjectInformation** to determine the length of the **SID** before retrieving its value. |

### `pvInfo` [out, optional]

A pointer to a buffer to receive the object information.

### `nLength` [in]

The size of the buffer pointed to by the *pvInfo* parameter, in bytes.

### `lpnLengthNeeded` [out, optional]

A pointer to a variable receiving the number of bytes required to store the requested information. If this variable's value is greater than the value of the *nLength* parameter when the function returns, the function returns FALSE, and none of the information is copied to the *pvInfo* buffer. If the value of the variable pointed to by *lpnLengthNeeded* is less than or equal to the value of *nLength*, the entire information block is copied.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa)

[GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity)

[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa)

[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectinformationa)

[SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity)

[USEROBJECTFLAGS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-userobjectflags)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)

## Remarks

> [!NOTE]
> The winuser.h header defines GetUserObjectInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).