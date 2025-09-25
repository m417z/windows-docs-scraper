# RasEapGetInfo function

## Description

The RAS connection manager calls
**RasEapGetInfo** to obtain a set of function pointers for a specified authentication protocol.

## Parameters

### `dwEapTypeId` [in]

Specifies the authentication protocol for which to obtain information.

### `pEapInfo` [out]

Pointer to a
[PPP_EAP_INFO](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_info) structure. The structure receives members that RAS sets to identify the structure version and the authentication protocol for which function pointers are requested. For more information, see
[PPP_EAP_INFO](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_info).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value should be an appropriate error code from Winerror.h, Raserror.h, or Mprerror.h.

## Remarks

The DLL that implements
**RasEapGetInfo** may support more than one authentication protocol. The *dwEapTypeId* parameter specifies for which authentication protocol to obtain information.

Implementations of EAP must export the
**RasEapGetInfo** function, since RAS uses
**RasEapGetInfo** to obtain pointers to the other authentication protocol functions.

Upon initialization, the Connection Manager calls
**RasEapGetInfo** for each EAP DLL installed in the registry subkey, as explained in the
[EAP Overview](https://learn.microsoft.com/windows/win32/eap/eap-installation).

If the function returns any value other than **NO_ERROR**, RAS considers the authentication protocol to be non-functional. RAS posts an error to the Windows NT/Windows 2000 Event Log to indicate that this protocol did not start correctly and therefore is not available.

## See also

[EAP (Extensible Authentication Protocol) Overview](https://learn.microsoft.com/windows/win32/eap/about-extensible-authentication-protocol)

[EAP Functions](https://learn.microsoft.com/windows/win32/eap/eap-functions)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[PPP_EAP_INFO](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_info)