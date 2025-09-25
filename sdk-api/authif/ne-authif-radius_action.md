# RADIUS_ACTION enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The
**RADIUS_ACTION** type enumerates the responses that a NPS Extension DLL can generate in response to an Access-Request.

## Constants

### `raContinue`

NPS continues to process the request. NPS also continues to call
[RadiusExtensionProcess](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process) in other Extension DLLs.

### `raReject`

Return an Access-Reject packet. The Access-Request is declined. In this case, NPS does not call
[RadiusExtensionProcess](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process) in any other Extension DLLs.

### `raAccept`

NPS accepts the Access-Request. NPS does not continue to call
[RadiusExtensionProcess](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process) in this case. However, it does continue to obtain authorizations for the user requesting access.

## Remarks

Use the values for this enumeration only as the actions for the
[RadiusExtensionProcess](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process) and
[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex) functions.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Enumerations](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-enumerations)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[RadiusExtensionProcess](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process)

[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex)