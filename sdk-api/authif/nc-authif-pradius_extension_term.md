# PRADIUS_EXTENSION_TERM callback function

## Description

> [!NOTE]
> Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The **RadiusExtensionTerm** function is an application-defined function and is called by NPS prior to unloading the Extension DLL. Use **RadiusExtensionTerm** to perform any clean-up operations for the Extension DLL.

## Remarks

**RadiusExtensionTerm** is an optional function. The RADIUS Extension DLL need not implement **RadiusExtensionTerm**.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/win32/Nps/ias-about-internet-authentication-service)

[NPS Extensions Functions](https://learn.microsoft.com/windows/win32/Nps/ias-internet-authentication-service-functions)

[NPS Extensions Reference](https://learn.microsoft.com/windows/win32/Nps/ias-internet-authentication-service-reference)

[RadiusExtensionInit](https://learn.microsoft.com/windows/win32/api/authif/nc-authif-pradius_extension_init)