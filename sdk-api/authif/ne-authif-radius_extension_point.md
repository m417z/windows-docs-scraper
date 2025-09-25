# RADIUS_EXTENSION_POINT enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS.

The
**RADIUS_EXTENSION_POINT** enumeration type enumerates the possible points in the RADIUS request process when the
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2) function can be called.

## Constants

### `repAuthentication`

Indicates that the
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2) function is called at the point in the request process where authentication occurs.

### `repAuthorization`

Indicates that the
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2) function is called at the point in the request process where authorization occurs.

## Remarks

The **repPoint** member of the
[RADIUS_EXTENSION_CONTROL_BLOCK](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_extension_control_block) structure is of type
**RADIUS_EXTENSION_POINT**.

See
[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service) for a diagram that shows the request process.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Enumerations](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-enumerations)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[RADIUS_EXTENSION_CONTROL_BLOCK](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_extension_control_block)

[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2)