# RasDialA function

## Description

The
**RasDial** function establishes a RAS connection between a RAS client and a RAS server. The connection data includes callback and user-authentication information.

## Parameters

### `unnamedParam1` [in]

Pointer to a
[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85)) structure that specifies a set of
**RasDial** extended features to enable. Set this parameter to **NULL** if there is not a need to enable these features.

### `unnamedParam2` [in]

Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `unnamedParam3` [in]

Pointer to a
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure that specifies calling parameters for the RAS connection. Use the
[RasGetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrydialparamsa) function to retrieve a copy of this structure for a particular phone-book entry.

The caller must set the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure's **dwSize** member to sizeof(**RASDIALPARAMS**) to identify the version of the structure being passed.

If the **szPhoneNumber** member of the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure is an empty string,
**RasDial** uses the phone number stored in the phone-book entry.

### `unnamedParam4` [in]

Specifies the nature of the *lpvNotifier* parameter. If *lpvNotifier* is **NULL**, *dwNotifierType* is ignored. If *lpvNotifier* is not **NULL**, set *dwNotifierType* to one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The *lpvNotifier* parameter points to a [RasDialFunc](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc) callback function. |
| **1** | The *lpvNotifier* parameter points to a [RasDialFunc1](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc1) callback function. |
| **2** | The *lpvNotifier* parameter points to a [RasDialFunc2](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc2) callback function. |

### `unnamedParam5` [in]

Specifies a window handle or a
[RasDialFunc](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc),
[RasDialFunc1](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc1), or
[RasDialFunc2](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc2) callback function to receive
**RasDial** event notifications. The *dwNotifierType* parameter specifies the nature of *lpvNotifier*. Please refer to its description preceding for further detail.

If this parameter is not **NULL**,
**RasDial** sends the window a message, or calls the callback function, for each
**RasDial** event. Additionally, the
**RasDial** call operates asynchronously:
**RasDial** returns immediately, before the connection is established, and communicates its progress via the window or callback function.

If *lpvNotifier* is **NULL**, the
**RasDial** call operates synchronously:
**RasDial** does not return until the connection attempt has completed successfully or failed.

If *lpvNotifier* is not **NULL**, notifications to the window or callback function can occur at any time after the initial call to
**RasDial**. Notifications end when one of the following events occurs:

* The connection is established. In other words, the RAS connection state is RASCS_Connected.
* The connection fails. In other words, *dwError* is nonzero.
* [RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) is called on the connection.

The callback notifications are made in the context of a thread captured during the initial call to
**RasDial**.

### `unnamedParam6` [out]

Pointer to a variable of type **HRASCONN**. Set the **HRASCONN** variable to **NULL** before calling
**RasDial**. If
**RasDial** succeeds, it stores a handle to the RAS connection into **lphRasConn*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS** and a handle to the RAS connection is returned in the variable pointed to by *lphRasConn*.

If the function fails, the return value is from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## Remarks

Errors that occur after the immediate return can be detected by
[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa). Data is available until an application calls
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) to hang up the connection.

An application must eventually call
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) whenever a non-**NULL** connection handle is stored into **lphRasConn*. This applies even if
**RasDial** returns a nonzero (error) value.

An application can safely call
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) from a
**RasDial** notifier callback function. If this is done, however, the hang-up does not occur until the routine returns.

If the structure pointed to by *lpRasDialExtensions* enables **RDEOPT_PausedStates**, the
**RasDial** function pauses whenever it enters a state in which the **RASCS_PAUSED** bit is set to one. To restart
**RasDial** from such a paused state, call
**RasDial** again, passing the connection handle returned from the original
**RasDial** call in **lphRasConn*. The same notifier used in the original
**RasDial** call must be used when restarting from a paused state.

The *lpvNotifier* parameter is a handle to a window to receive progress notification messages. In a progress notification message, *wParam* is the equivalent of the *rasconnstate* parameter of
[RasDialFunc](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc) and
[RasDialFunc1](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc1), and *lParam* is the equivalent of the *dwError* parameter of
**RasDialFunc** and
**RasDialFunc1**.

The progress notification message uses a system registered message code. You can obtain the value of this message code as follows:

```cpp
UINT unMsg = RegisterWindowMessageA( RASDIALEVENT );
if (unMsg == 0)
    unMsg = WM_RASDIALEVENT;

```

RAS supports referenced connections. If the entry being dialed is already connected,
**RasDial** returns **SUCCESS** and the connection is referenced. To disconnect the connection, each
**RasDial** on the connection should be matched by a
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa).

Because some phone-book entries require Extensible Authentication Protocol (EAP) for authentication, the caller should call
[RasGetEapUserIdentity](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuseridentitya) before calling
**RasDial**. If
**RasGetEapUserIdentity** returns **ERROR_INVALID_FUNCTION_FOR_ENTRY**, the phone-book entry does not require EAP. However, if
**RasGetEapUserIdentity** returns NO_ERROR, the caller should copy the EAP identity information from
**RasGetEapUserIdentity** into the **RasEapInfo** member of
[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85)), and the **szUserName** member of
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)). See
**RasGetEapUserIdentity** for more information. If the phone-book entry requires EAP, the **dwfOptions** member of the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure for the entry contains the **RASEO_RequireEAP** flag.

To specify that
**RasDial** should enter a **RASCS_CallbackSetByCaller** state, set *lpRasDialParams*->**szCallbackNumber** to "*" on the initial call to
**RasDial**. When the notification handler is called with this state, set the callback number to a number supplied by the user.

> [!NOTE]
> The ras.h header defines RasDial as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Dialable Addresses](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr)

[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85))

[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85))

[RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga)

[RasDialFunc](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc)

[RasDialFunc1](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc1)

[RasDialFunc2](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc2)

[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa)

[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

[Virtual Private Network Connections](https://learn.microsoft.com/windows/desktop/RRAS/virtual-private-network-connections)

[WM_RASDIALEVENT](https://learn.microsoft.com/windows/desktop/RRAS/wm-rasdialevent)