# PRADIUS_EXTENSION_INIT callback function

## Description

> [!NOTE]
> Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The **RadiusExtensionInit** function is an application-defined function and is called by NPS while the service is starting up. Use **RadiusExtensionInit** to perform any initialization operations for the Extension DLL.

## Return value

If the function succeeds, the return value is `NO_ERROR`. If the function fails, the return value should be an appropriate error code from WinError.h.

## Remarks

A return value other then `NO_ERROR` will cause NPS to fail to start.

**RadiusExtensionInit** is an optional function. The RADIUS Extension DLL need not implement **RadiusExtensionInit**.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/win32/Nps/ias-about-internet-authentication-service)

[NPS Extensions Functions](https://learn.microsoft.com/windows/win32/Nps/ias-internet-authentication-service-functions)

[NPS Extensions Reference](https://learn.microsoft.com/windows/win32/Nps/ias-internet-authentication-service-reference)

[RadiusExtensionTerm](https://learn.microsoft.com/windows/win32/api/authif/nc-authif-pradius_extension_term)