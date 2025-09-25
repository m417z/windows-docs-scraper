# RasCustomScriptExecuteFn callback function

## Description

RAS calls the
**RasCustomScriptExecute** function when establishing a connection for a phone-book entry that has the
[RASEO_CustomScript](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) option set.

## Parameters

### `hPort` [in]

Handle to the port on which the connection is established. Use this handle when sending or receiving data on the port.

### `lpszPhonebook` [in]

Pointer to a Unicode string that contains the path to the phone book in which the entry for the connection resides.

### `lpszEntryName` [in]

Pointer to a Unicode string that contains the name of the entry that was dialed to establish the connection.

### `pfnRasGetBuffer` [in]

Pointer to a function of type
[PFNRASGETBUFFER](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer). The custom-scripting DLL should use this function to allocate memory to send data to the server.

### `pfnRasFreeBuffer` [in]

Pointer to a function of type
[PFNRASFREEBUFFER](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasfreebuffer). The custom-scripting DLL should use this function to free memory allocated by the
[pfnRasGetBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer) function.

### `pfnRasSendBuffer` [in]

Pointer to a function of type
[PFNRASSENDBUFFER](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrassendbuffer). The custom-scripting DLL uses this function to communicate with the server over the specified port.

### `pfnRasReceiveBuffer` [in]

Pointer to a function of type
[PFNRASRECEIVEBUFFER](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasreceivebuffer). The custom-scripting DLL uses this function to communicate with the server over the specified port.

### `pfnRasRetrieveBuffer` [in]

Pointer to a function of type
[PFNRASRETRIEVEBUFFER](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasretrievebuffer). The custom-scripting DLL uses this function to communicate with the server over the specified port.

### `hWnd` [in]

Handle to a window that the custom-scripting DLL can use to present a user interface to the user.

### `pRasDialParams` [in]

Pointer to a Unicode
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure. This structure contains the authentication credentials for the user. The custom-scripting DLL can modify the **szUserName**, **szPassword**, and **szDomain** members of this structure. The Point-to-Point Protocol (PPP) will use whatever is stored in these members when
**RasCustomScriptExecute** returns.

### `pvReserved`

#### - pRasCustomScriptExtensions [in]

Pointer to a
[RASCUSTOMSCRIPTEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376738(v=vs.85)) structure. This structure contains pointers to additional functions for the custom-scripting DLL.

**Windows 2000:** This parameter is supported on Windows SP2 and later.

## Return value

If the function succeeds, the return value should be **ERROR_SUCCESS**.

If the function fails, the return value should be an appropriate error code from Winerror.h or Raserror.h.

## Remarks

When RAS calls
**RasCustomScriptExecute**, the *pRasDialParams* parameter will point to the Unicode
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure. That is, the structure contains only Unicode strings.

In some cases, the **szUserName** of the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure will be an empty string. In these cases, the custom-scripting DLL should use the Unicode version of the
[GetUserName](https://learn.microsoft.com/windows/desktop/DirectShow/iamtimelineobj-getusername) function to obtain the name of the current user.

## See also

[RAS Custom-Scripting](https://learn.microsoft.com/windows/desktop/RRAS/ras-custom-scripting)

[RasFreeBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasfreebuffer)

[RasGetBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer)

[RasReceiveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasreceivebuffer)

[RasRetrieveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasretrievebuffer)

[RasSendBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrassendbuffer)