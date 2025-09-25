# PRADIUS_EXTENSION_PROCESS callback function

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The
**RadiusExtensionProcess** function is an application-defined function and is called by NPS for each authentication or accounting packet that NPS receives from the network access server (NAS).

## Parameters

### `pAttrs` [in]

Pointer to an array of
[attributes](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute) from the request. The array is terminated by an attribute with **dwAttrType** set to **ratMinimum**. These attributes should be treated as read-only; they should not be modified by
**RadiusExtensionProcess**. Also, these attributes should not be referenced in any way after
**RadiusExtensionProcess** returns.

### `pfAction` [out]

Pointer to a value of type
[RADIUS_ACTION](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_action), initially set to **raContinue**. This parameter specifies the action that NPS should take in response to an Access-Request.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value should be an appropriate error code from Winerror.h.

## Remarks

If the return value is anything other than **NO_ERROR**, NPS discards the request.

NPS supports multiple Extension DLLs. NPS calls
**RadiusExtensionProcess** for each of the DLLs listed in the registry. For more information see
[Setting Up the Extension DLLs](https://learn.microsoft.com/windows/desktop/Nps/ias-setting-up-the-extension-and-authorization-dlls).

The Extension DLL may export
[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex) instead of
**RadiusExtensionProcess**. The Extension DLL may export
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2).

For more information on the use of this function, see [NPS Extensions Process](https://learn.microsoft.com/windows/desktop/Nps/ias-authentication-and-authorization-process).

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Functions](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-functions)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[RADIUS_ACTION](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_action)

[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute)

[RADIUS_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_attribute_type)

[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2)

[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex)