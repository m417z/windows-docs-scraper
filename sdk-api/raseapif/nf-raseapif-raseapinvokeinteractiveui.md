# RasEapInvokeInteractiveUI function

## Description

The RAS connection manager calls the
**RasEapInvokeInteractiveUI** function to display a dialog to obtain authentication data from the user.

## Parameters

### `dwEapTypeId` [in]

Specifies the authentication protocol for which to invoke the interactive UI.

### `hwndParent` [in]

Handle to the parent window for the dialog.

### `pUIContextData` [in]

Pointer to context data for the interactive UI. The authentication protocol provides a pointer to this data as a member of the
[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output) structure. The RAS Connection Manager receives the
**PPP_EAP_OUTPUT** structure as an output parameter from the
[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)) function.

### `dwSizeOfUIContextData` [in]

Specifies the size of the context data. The authentication protocol provides the size as a member of the
[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output) structure. The RAS Connection Manager receives the
**PPP_EAP_OUTPUT** structure as an output parameter from the
[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)) function.

### `ppDataFromInteractiveUI`

[out[ Pointer to a pointer variable. On successful return, this pointer variable points to a memory buffer that contains the data obtained by the interactive UI. The interactive UI allocates this memory. RAS passes this data back to the authentication protocol in the
[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input) structure, then RAS frees this memory by calling
[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory).

If the interactive UI does not obtain any user-specific data, the pointer that *ppUserData* points to should be set to **NULL**.

### `pdwSizeOfDataFromInteractiveUI` [out]

Pointer to a **DWORD** variable that receives the size of the data returned from the interactive UI. If the interactive UI does not obtain any user-specific data, the **DWORD** variable should be set to zero.

## Return value

If the function succeeds, the return value is **NO_ERROR**. Check the *ppDataFromInteractiveUI* and *lpdwSizeOfDataFromInteractiveUI* parameters to determine if the function returned data from the interactive UI.

If the function was not able to allocate memory for the data, the return value should be **ERROR_NOT_ENOUGH_MEMORY**.

If the function fails in some other way, the return value should be an appropriate error code from Winerror.h, Raserror.h, or Mprerror.h.

## Remarks

The DLL that implements the
**RasEapInvokeInteractiveUI** and
[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory) functions may support more than one authentication protocol. The *dwEapTypeId* parameter specifies the authentication protocol for which to invoke the interactive UI.

A pointer to the data returned from the interactive UI is passed back to the authentication protocol in the **pDataFromInteractiveUI** member of
[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input) structure. The
**PPP_EAP_INPUT** structure is passed as a parameter to the
[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)) function.

The interactive user interface must support
[WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) messages where
[LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85))(*wParam*) equals IDCANCEL.

## See also

[EAP Functions](https://learn.microsoft.com/windows/win32/eap/eap-functions)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[Interactive User Interface](https://learn.microsoft.com/windows/win32/eap/interactive-user-interface)

[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input)

[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output)

[RasEapFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapfreememory)

[RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity)

[RasEapInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeconfigui)

[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85))