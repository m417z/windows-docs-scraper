# PRADIUS_EXTENSION_FREE_ATTRIBUTES callback function

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The
**RadiusExtensionFreeAttributes** function is an application-defined function and is called by NPS to free the memory occupied by attributes returned by
[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex).

## Parameters

### `pAttrs`

Pointer to an array of attributes. The
**RadiusExtensionFreeAttributes** function should deallocate the memory occupied by these attributes.

These attributes were returned in the *pOutAttrs* parameter in a previous call to the
[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex) function.

## Remarks

If you implement
[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex), you must also implement
**RadiusExtensionFreeAttributes**.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Functions](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-functions)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[RadiusExtensionProcessEx](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_ex)