# PRADIUS_EXTENSION_PROCESS_2 callback function

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The
*RadiusExtensionProcess2* function is an application defined-function and is called by NPS for each authentication or accounting packet that NPS receives from the network access server (NAS). This function is similar to
[RadiusExtensionProcess](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process). However,
*RadiusExtensionProcess2* enables an Extension DLL to add, modify, and remove attributes to and from the authentication request or response.

## Parameters

### `pECB` [in, out]

Pointer to a
[RADIUS_EXTENSION_CONTROL_BLOCK](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_extension_control_block) structure. The members of this structure contain values and function pointers that enable the NPS Extension DLL to process the RADIUS packet.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value should be an appropriate error code from WinError.h.

## Remarks

If the return value is anything other than **NO_ERROR**, NPS discards the request.

The following attributes are read-only. Extension DLLs that implement *RadiusExtensionProcess2* cannot add, modify, or remove these attributes within a request or response contained in a [RADIUS_EXTENSION_CONTROL_BLOCK](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_extension_control_block).

* **ratCode**
* **ratIdentifier**
* **ratAuthenticator**
* **ratSrcIPAddress**
* **ratSrcPort**
* **ratProvider**
* **ratUniqueId**
* **ratSrcIPv6Address**

NPS supports multiple Extension DLLs. NPS calls
*RadiusExtensionProcess2* for each of the DLLs listed in the registry. For more information see
[Setting Up the Extension DLLs](https://learn.microsoft.com/windows/desktop/Nps/ias-setting-up-the-extension-and-authorization-dlls).

NPS Extension DLLs that export
*RadiusExtensionProcess2* do not need to export
[RadiusExtensionFreeAttributes](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_free_attributes).

For more information on the use of this function, see [NPS Extensions Process](https://learn.microsoft.com/windows/desktop/Nps/ias-authentication-and-authorization-process).

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Functions](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-functions)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[RadiusExtensionProcess](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process)

[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex)